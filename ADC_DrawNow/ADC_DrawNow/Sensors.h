/*
 * Sensors.h
 *
 * Created: 10/7/2020 6:32:46 PM
 *  Author: hp
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_

#include "ADC.h"



uint16 Volt_read();
uint16 Temp_read();
uint32 Pressure_Read();



#endif /* SENSORS_H_ */