#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "fsl_tpm.h"

#define RED 18u
#define GREEN 19u
#define BLUE 1u

typedef struct{
	uint16_t TIMER_MOD;
	uint8_t ROJO;
	uint8_t VERDE;
	uint8_t AZUL;
} state;


int main(void) {

    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    BOARD_InitDebugConsole();

    //Configuración del TPM

    tpm_config_t config;
    TPM_GetDefaultConfig(&config);
	config.prescale= kTPM_Prescale_Divide_128;
	TPM_Init(TPM0, &config);


    //Máquina de Estados

    state FSM[3];
    FSM[0]=(state ){.ROJO=0u, .VERDE=0u, .AZUL=1u, .TIMER_MOD=256u};
    FSM[1]=(state ){.ROJO=1u, .VERDE=0u, .AZUL=1u, .TIMER_MOD=768u};
    FSM[2]=(state ){.ROJO=1u, .VERDE=1u, .AZUL=0u, .TIMER_MOD=1280u};

    uint8_t actual_state= 0;
    uint8_t Timer_init= 0;
    uint32_t TIMER_FLAG;

    while(1) {
    	GPIO_WritePinOutput(GPIOB, RED, FSM[actual_state].ROJO); //Del GPIOB, en donde tienes direccionado RED (18u) le asignas el valor que tenga ROJO en la pinshi máquina
    	GPIO_WritePinOutput(GPIOD, BLUE, FSM[actual_state].AZUL);
    	GPIO_WritePinOutput(GPIOB, GREEN, FSM[actual_state].VERDE);

    	TIMER_FLAG=TPM0->STATUS;




    	switch(actual_state){
    	case 0:
     		if(Timer_init==0){
     			Timer_init=1;
     			TPM_SetTimerPeriod(TPM0, FSM[0].TIMER_MOD);
     			TPM_StartTimer(TPM0, kTPM_SystemClock);
     		}
     		if(TIMER_FLAG){
     		    TPM_ClearStatusFlags(TPM0, 1u<8u);
     		    Timer_init=0;
     		    TPM_StopTimer(TPM0);
     		    TPM0->CNT=0;
     		   actual_state =1;
     		}
     		break;
    	case 1:
			if(Timer_init==0){
				Timer_init=1;
				TPM_SetTimerPeriod(TPM0, FSM[1].TIMER_MOD);
				TPM_StartTimer(TPM0, kTPM_SystemClock);
			}
			if(TIMER_FLAG){
				TPM_ClearStatusFlags(TPM0, 1u<8u);
				Timer_init=0;
				TPM_StopTimer(TPM0);
				TPM0->CNT=0;
				actual_state =2;
			}
		break;

    	case 2:
			if(Timer_init==0){
				Timer_init=1;
				TPM_SetTimerPeriod(TPM0, FSM[2].TIMER_MOD);
				TPM_StartTimer(TPM0, kTPM_SystemClock);
			}
			if(TIMER_FLAG){
				TPM_ClearStatusFlags(TPM0, 1u<8u);
				Timer_init=0;
				TPM_StopTimer(TPM0);
				TPM0->CNT=0;
				actual_state =0;
			}
		break;

     	}
     	}

}
