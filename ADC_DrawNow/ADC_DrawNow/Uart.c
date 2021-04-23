#include "data_types.h"
#include "Uart.h"
#include "Mem_map.h"

#define  SPECIAL_CHARACTER_SENTENCE_END           ('#') 

#define NULL_CHARACTER                             ('\0')

static ptr_call_back Static_FUNC_Call_Back[2];


static void Set_Baud_rate()
{
	
	UART_UBRRL=51;
}

static void Set_Frame()
{
	Set_BIT(UART_UCSRC,UCSZ0);
	Set_BIT(UART_UCSRC,UCSZ1);
	CLEAR_BIT(UART_UCSRB,UCSZ2);

}


void UART_Init()
{
	Set_Baud_rate();
	Set_Frame();
	
	Static_FUNC_Call_Back[0]=NULL_PTR;
	Static_FUNC_Call_Back[1]=NULL_PTR;
}

//void UART_Update();



void UART_State(t_Uart_status state)
{

	switch(state)
	{
		case UART_RX:
		Set_BIT(UART_UCSRB,RXEN);
		CLEAR_BIT(UART_UCSRB,TXEN);
		break;
		
		case UART_TX:
		CLEAR_BIT(UART_UCSRB,RXEN);
		Set_BIT(UART_UCSRB,TXEN);
		break;
		
		case Both:
		Set_BIT(UART_UCSRB,TXEN);
		Set_BIT(UART_UCSRB,RXEN);
		break;

	}

}

//SENDER_FUNCTION

//void Set_UART_ARR_DATA(uint8 *pdata);

void Set_UART_data(uint8 data)
{
	while(!(READ_BIT(UART_UCSRA,UDRE)) );
	UART_UDR=data;

}

void Set_UART_ARR_DATA(uint8 *pdata,uint8 arr_len)
{
	uint8 i=0;
	while ((i<arr_len) &&(pdata[i]!=SPECIAL_CHARACTER_SENTENCE_END) )
	{
		Set_UART_data(pdata[i]);
		i++;
	}

}



//RECIVING FUNCTIONS

//Function_with_Block

uint8 Get_UART_data()
{
	
	while(!(READ_BIT(UART_UCSRA,RXC)) );
	
	return UART_UDR;

}

void Get_UART_ARR_DATA(uint8 *pdata,uint8 arr_len)
{
	uint8 i=0;
	
	while ((i<arr_len-1) &&(pdata[i]!=SPECIAL_CHARACTER_SENTENCE_END) )
	{
		pdata[i]=Get_UART_data();
		i++;
	}
	
	
}


//INTERRUPT FUNC
void UART_RX_Interrupt_State(t_UART_INT_State state)
{
	switch(state)
	{
		case UART_INTERRUPT_ENABLE:
		
		Set_BIT(UART_UCSRB,RXCIE);
		
		break;
		
		case UART_INTERRUPT_DISABLE:
		
		CLEAR_BIT(UART_UCSRB,RXCIE);
		
		break;
		
		default:
		//Do nothing
		break;
		
		
	}
	
	
}

void UART_TX_Interrupt_State(t_UART_INT_State state)
{
	switch(state)
	{
		case UART_INTERRUPT_ENABLE:
		
		Set_BIT(UART_UCSRB,TXCIE);
		
		break;
		
		case UART_INTERRUPT_DISABLE:
		
		CLEAR_BIT(UART_UCSRB,TXCIE);
		
		break;
	
	}


}

void UART_RX_Set_Call_Back(ptr_call_back Func_ptr)
{
	
	Static_FUNC_Call_Back[0]=Func_ptr;
	
}

void UART_TX_Set_Call_Back(ptr_call_back Func_ptr)
{
	
	Static_FUNC_Call_Back[1]=Func_ptr;
	
}
ISR(UART_RX_vect)
{
	if (Static_FUNC_Call_Back[0]!=NULL_PTR)
	{
		Static_FUNC_Call_Back[0]();
	}
	
	
}

//Services

void Send_Nummber(uint64 Num)
{
	uint8 data_8_bit=0;
	while (Num!=0)
	{

		data_8_bit=Num&0xff;
		
		Set_UART_data(data_8_bit);
		
		Num=(Num>>8);
	}
	
	

}
void Get_Numbber(uint64*num_ptr)
{
	//uint8 i;
	//uint64 rec_data=0;
	/*
	for (i=0;i<4;i++)
	{
		rec_data=Get_UART_data();
		rec_data=
	}
	*/
	
	
}

void Speaker_Uart_Talking_Protcol(uint8 *Ptr_str,uint8 len)
{
	uint8 i=0;
	if ((len>Sentence_Limit))
	{
		len=Sentence_Limit-1;
	}
	while ((i<len)&&(Ptr_str[i]!=NULL_CHARACTER) && (Ptr_str[i]!=SPECIAL_CHARACTER_SENTENCE_END))
	{
		Set_UART_data(Ptr_str[i]);
		i++;
	}
	
	
}

void Listener_Uart_Talking_Protcol(uint8 *Ptr_str,uint8 len)
{
	uint8 i=0;
	if ((len>Sentence_Limit))
	{
		len=Sentence_Limit-1;
	}
	while ((i<len) && (Ptr_str[i]!=NULL_CHARACTER) && (Ptr_str[i]!=SPECIAL_CHARACTER_SENTENCE_END))
	{
		Ptr_str[i]=Get_UART_data();
		i++;
	}
	i++;
	Ptr_str[i]=NULL_CHARACTER;
	
}
void UART_Send_String(uint8 *Str_Ptr)
{
	uint8 i=0;
	while (Str_Ptr[i]!=NULL_CHARACTER)
	{
		if (Str_Ptr[i]==SPECIAL_CHARACTER_SENTENCE_END)
		{
			
		}
		else
		{		
		Set_UART_data(Str_Ptr[i]);
		i++;
		}
		
	}
	
	
}