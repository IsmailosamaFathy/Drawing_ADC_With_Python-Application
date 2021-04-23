/*
 * ADC_DrawNow.c
 *
 * Created: 4/24/2021 12:08:40 AM
 * Author : hp
 */ 

#include "Display.h"


int main(void)
{
    /* Replace with your application code */
	Display_Init();
    while (1) 
    {
		Display_Update();
    }
}

