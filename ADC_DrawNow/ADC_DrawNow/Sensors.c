/*
 * Sensors.c
 *
 * Created: 10/7/2020 6:33:02 PM
 *  Author: hp
 */ 
#include "ADC.h"
#include "Sensors.h"
#include "Port_h.h"
uint16 Volt_read()
{
	uint16 adc;
   adc=ADC_Read(POT_CHANNEL);
   adc=((uint32)adc*5000)/1024;
   return adc;
}
uint16 Temp_read()
{
  	uint16 temp;
  	temp=ADC_Read(LM35_Channel);
  	temp=((uint32)temp*5000)/1024;
	temp=temp/10;  
  	return temp;

}
uint32 Pressure_Read()
{
  uint32 pressure;
  
  pressure=ADC_Read(PRESSURE_SENSOR_CHANNEL);
  
  pressure=(pressure*5)/1024;
  
  pressure=pressure/5.1;
  
  pressure+=0.095;
  
  pressure=pressure/0.009-1.51279;
  
  pressure=pressure*0.145;
  
  pressure=pressure*9.86923267;
  
  return pressure;

}