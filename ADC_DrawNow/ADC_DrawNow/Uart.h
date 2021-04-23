/*
 * Uart.h
 *
 * Created: 11/13/2020 3:13:36 PM
 *  Author: hp
 */ 


#ifndef UART_H_
#define UART_H_

#include "data_types.h"


#define Sentence_Limit               (100)

typedef enum
{
	UART_RX=0,
	UART_TX,
	Both
}t_Uart_status;

typedef enum
{
	UART_INTERRUPT_ENABLE,
	UART_INTERRUPT_DISABLE,
}t_UART_INT_State;


void UART_Init();

//void UART_Update();



void UART_State(t_Uart_status state);

//SET_FUNC

//void Set_UART_ARR_DATA(uint8 *pdata);

void Set_UART_data(uint8 data);

void Set_UART_ARR_DATA(uint8 *pdata,uint8 arr_len);

void UART_Send_String(uint8 *Str_Ptr);

//GET FUNC

uint8 Get_UART_data();

void Get_UART_ARR_DATA(uint8 *pdata,uint8 arr_len);


//INTERRUPT FUNC
void UART_RX_Interrupt_State(t_UART_INT_State state);

void UART_TX_Interrupt_State(t_UART_INT_State state);

void UART_RX_Set_Call_Back(ptr_call_back Func_ptr);

void UART_TX_Set_Call_Back(ptr_call_back Func_ptr);



void Send_Nummber(uint64 Num);

void Get_Numbber(uint64*num_ptr);


void Speaker_Uart_Talking_Protcol(uint8 *Ptr_str,uint8 len);

void Listener_Uart_Talking_Protcol(uint8 *Ptr_str,uint8 len);





#endif /* UART_H_ */