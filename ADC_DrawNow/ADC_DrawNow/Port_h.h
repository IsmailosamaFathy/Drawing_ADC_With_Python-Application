/*
 * Port_h.h
 *
 * Created: 9/27/2020 8:08:04 PM
 *  Author: hp
 */ 


#ifndef PORT_H_H_
#define PORT_H_H_

#include "DIO_Interface.h"



// Board_Clock
#define F_CPU 8000000UL

/*******************SSD*********************/

#define SSD_DIRC     PC

#define SSD_PORT     PC

#if ((SSD_CONNECTION)==(SSD_ML))

#define SSD_CON_PIN_DIRC     PB

#define SSD_CON_PIN_PORT     PB

#define SSD1                 PINB0

#define SSD2                 PINB1

#define SSD3                 PINB2

#define SSD4                 PINB3

#endif


#if ((SSD_CONNECTION)==(SSD_DF_Port))

#define SECOND_SSD_DIRC     DDRB

#define SECOND_SSD_PORT     PORTB

#define SSD_1               PINB0 

#endif


/*****************SSD_END**********************/



/**********************LCD************************/

#define LCD_DATA_DIRC           PB

#define LCD_DATA_PORT           PB

#define EN          PIND2 

#define RS          PIND3

/***********************END_LCD********************************/


#define LM35_Pin                  PINA0

#define LM35_Channel              ChanneL0


#define POT_PIN                   PINA1

#define POT_CHANNEL              ChanneL1

   

#define PRESSURE_SENSOR_PIN       PINA2

#define PRESSURE_SENSOR_CHANNEL   ChanneL2




/*******************************SENSORS*********************************/

/*****************************KEYPAD*********************************/
#define Keypad_PORT                  PD

#define Keypad_INPUT_REG             PIND

#define KEYPAD_DATA_REG              PORTD  



/****************************TIMERS****************************/
/*********************TIMER1***********************************/
#define TIMER1_OCR1A_PIN              (PIND5)   

#define TIMER1_OCR1B_PIN              (PIND4) 

#define TIMER1_ICR1_PIN               (PIND6) 

/*************************Servo********************************/
#define SERVO_PIN           (TIMER1_OCR1B_PIN)

/*********************Ultra_Sonic****************************/

#define ECHO_PIN                                 (PIND6)   

/*****************************UART*************************/
//peripheral UART PINS
#define RX_PIN                       (PIND0)
#define TX_PIN                       (PIND1)

//GPIO_TIMERS Uart_Frame Pins 

#define GPIO_RX_PIN                       (PIND0)
#define GPIO_TX_PIN                       (PIND1)



#endif /* PORT_H_H_ */