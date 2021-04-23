/*
 * Display.c
 *
 * Created: 4/20/2021 2:11:05 AM
 *  Author: hp
 */ 
#include "Uart.h"
#include "LCD.h"
#include "ADC.h"
#include "Sensors.h"
#include <util/delay.h>
void Display_Init()
{
	LCD_Init();
    
	UART_Init();
	
	UART_State(Both);

	ADC_Init(AVCC,CLK_ADC_DIV_64);
	_delay_ms(500);
	ADC_Converstion(Conversion_on);
}



void Display_Update()
{
	static uint16 temp=0;
	uint8 x=0;
	temp=Volt_read();
	x=((uint16)temp/1000);
	
	Set_UART_data(x);
	
	LCD_goto(0,0);
	
	LCD_Number(x);
	
	_delay_ms(5000);
	
}