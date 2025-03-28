// ADAPTED MIRF EXAMPLE
// ESPIDF MIRF LIBRARY: https://github.com/nopnop2002/esp-idf-mirf/tree/master

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/timer/delay.h"
#include "mirf.h"
#include <stdbool.h>
#include "servo.h"
#include "arm_fsm.h"
#include "message_parser.h"

#define CONFIG_RECEIVER 0
#define CONFIG_SENDER 0
#define CONFIG_RADIO_CHANNEL 112
#define CONFIG_ADVANCED 1
#define CONFIG_RF_RATIO_1M 1
#define CONFIG_RETRANSMIT_DELAY 100
#define CONFIG_SLAVE 1

uint8_t buf[32];
bool nrf_flag=false;
#if CONFIG_ADVANCED
void AdvancedSettings(NRF24_t * dev)
{
#if CONFIG_RF_RATIO_2M
	Nrf24_SetSpeedDataRates(dev, 1);
#endif // CONFIG_RF_RATIO_2M

#if CONFIG_RF_RATIO_1M
	Nrf24_SetSpeedDataRates(dev, 0);
#endif // CONFIG_RF_RATIO_2M

#if CONFIG_RF_RATIO_250K
	Nrf24_SetSpeedDataRates(dev, 2);
#endif // CONFIG_RF_RATIO_2M
	Nrf24_setRetransmitDelay(dev, CONFIG_RETRANSMIT_DELAY);
}
#endif // CONFIG_ADVANCED

#if CONFIG_SLAVE
void slave(void *pvParameters){
    NRF24_t dev;
	Nrf24_init(&dev);
	uint8_t payload = 32;
	uint8_t channel = CONFIG_RADIO_CHANNEL;
	Nrf24_config(&dev, channel, payload);
    int ret = Nrf24_setRADDR(&dev, (uint8_t *)"2RECV");
	while (ret != NRF_OK) {
		ret = Nrf24_setRADDR(&dev, (uint8_t *)"2RECV");
	}

	// Set destination address using 5 characters
	ret = Nrf24_setTADDR(&dev, (uint8_t *)"2RECV");
	while (ret != NRF_OK) {
		ret = Nrf24_setTADDR(&dev, (uint8_t *)"2RECV");
	}
#if CONFIG_ADVANCED
	AdvancedSettings(&dev);
#endif // CONFIG_ADVANCED
    Nrf24_configRegister(NRF_STATUS, (1 << RX_DR) | (1 << TX_DS) | (1 << MAX_RT));

    //main loop
    while(1){
        arm_fsm_update();
       if(nrf_flag){
           if (Nrf24_dataReady(&dev)) {
            Nrf24_getData(&dev, buf);
            robot_command_t rob;
            parse_robot_message(buf, &rob);
            arm_set_target(rob.ship_id,rob.row,rob.col,rob.horizontal,PLACE);
            
            }
            nrf_flag=false;
		}

		DELAY_milliseconds(1);
        }
    }
#endif


#if CONFIG_RECEIVER
void receiver(void *pvParameters)
{
	NRF24_t dev;
	Nrf24_init(&dev);
	uint8_t payload = 32;
	uint8_t channel = CONFIG_RADIO_CHANNEL;
	Nrf24_config(&dev, channel, payload);

	// Set my own address using 5 characters
	int ret = Nrf24_setRADDR(&dev, (uint8_t *)"ABCDE");
	if (ret != NRF_OK) {
		while(1) { 
            ret = Nrf24_setRADDR(&dev, (uint8_t *)"ABCDE");
            DELAY_milliseconds(1);
        }
	}

#if CONFIG_ADVANCED
	AdvancedSettings(&dev);
#endif // CONFIG_ADVANCED

	// Print settings
	Nrf24_printDetails(&dev);

	uint8_t buf[32];

	// Clear RX FiFo
	while(1) {
		if (Nrf24_dataReady(&dev) == false) break;
		Nrf24_getData(&dev, buf);
	}

	while(1) {
		// Wait for received data
		if (Nrf24_dataReady(&dev)) {
			Nrf24_getData(&dev, buf);
		}
		DELAY_milliseconds(1); // Avoid WatchDog alerts
	}
}
#endif // CONFIG_RECEIVER


#if CONFIG_SENDER
void sender(void *pvParameters)
{
	NRF24_t nrf;
	Nrf24_init(&nrf);
	uint8_t payload = 32;
	uint8_t channel = CONFIG_RADIO_CHANNEL;
	Nrf24_config(&nrf, channel, payload);

	// Set destination address using 5 characters
	int ret = Nrf24_setTADDR(&nrf, (uint8_t *)"3RECV");
	if (ret != NRF_OK) {
		while(1) { DELAY_milliseconds(1); }
	}

#if CONFIG_ADVANCED
	AdvancedSettings(&nrf);
#endif // CONFIG_ADVANCED

	// Print settings
	Nrf24_printDetails(&nrf);

	uint8_t buf[32] = "cowabunga.";
	while(1) {
		Nrf24_send(&nrf, buf);
		Nrf24_isSend(&nrf, 1000);
		DELAY_milliseconds(1);
	}
}
#endif // CONFIG_SENDER
void nrf_irq(){
    nrf_flag=true;
}
uint8_t counter=0;
void servo_steps(){
    if(counter==0){
        counter++;
        servos[0].nextAngle = calculateAngle(100); //mid angle P6
        servos[1].nextAngle = calculateAngle(90); //wrist P5
        servos[2].nextAngle = calculateAngle(100); //bot rotate P8
        servos[3].nextAngle = calculateAngle(80); //bot angle P7
    }else if(counter==1){
        counter++;
        servos[0].nextAngle = calculateAngle(70); //mid angle
        servos[1].nextAngle = calculateAngle(90); //wrist
        servos[2].nextAngle = calculateAngle(120); //bot rotate
        servos[3].nextAngle = calculateAngle(20);
    }else{
        counter=0;
        servos[0].nextAngle = calculateAngle(45); //mid angle
        servos[1].nextAngle = calculateAngle(0); //wrist
        servos[2].nextAngle = calculateAngle(140); //bot rotate
        servos[3].nextAngle = calculateAngle(10);
    }
}
void main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    //TMR0_OverflowCallbackRegister(Buttoncheck);
    TMR2_Start();
    nRF24_IRQ_SetInterruptHandler(nrf_irq);
    TMR0_Stop();  
        TMR2_Stop();  
    enablePWM();
    PWM1_16BIT_Disable();
//    TMR0_OverflowCallbackRegister(servo_steps);
//    initServo();
//    TMR0_Start();
#if CONFIG_SLAVE
	slave(NULL);
#endif
    
#if CONFIG_RECEIVER
	receiver(NULL);
#endif

#if CONFIG_SENDER
    sender(NULL);
#endif

}