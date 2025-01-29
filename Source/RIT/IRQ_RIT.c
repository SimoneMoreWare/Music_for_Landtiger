/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "LPC17xx.h"
#include "RIT.h"
#include "../led/led.h"
#include "../timer/timer.h"

/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
#define UPTICKS 1


//SHORTENING UNDERTALE: TOO MANY REPETITIONS
NOTE song[] = 
{
		// 1
	{NOTE_D3, time_16th},
	{NOTE_D3, time_16th},
	{NOTE_D4, time_8th},
	{NOTE_A3, time_8th},
	{REST, time_16th},
	{NOTE_GS3, time_16th},
	{REST, time_16th},
	{NOTE_G3, time_8th},
	{NOTE_F3, time_16th * 2},
	{NOTE_D3, time_16th},
	{NOTE_F3, time_16th},
	{NOTE_G3, time_16th},

		// 2
	{NOTE_C3, time_16th},
	{NOTE_C3, time_16th},
	{NOTE_D4, time_8th},
	{NOTE_A3, time_8th},
	{REST, time_16th},
	{NOTE_GS3, time_16th},
	{REST, time_16th},
	{NOTE_G3, time_8th},
	{NOTE_F3, time_16th * 2},
	{NOTE_D3, time_16th},
	{NOTE_F3, time_16th},
	{NOTE_G3, time_16th},

		// 3
	{NOTE_C3B, time_16th},
	{NOTE_C3B, time_16th},
	{NOTE_D4, time_8th},
	{NOTE_A3, time_8th},
	{REST, time_16th},
	{NOTE_GS3, time_16th},
	{REST, time_16th},
	{NOTE_G3, time_8th},
	{NOTE_F3, time_16th * 2},
	{NOTE_D3, time_16th},
	{NOTE_F3, time_16th},
	{NOTE_G3, time_16th},

		// 4
	{NOTE_GS2, time_16th},
	{NOTE_GS2, time_16th},
	{NOTE_D4, time_8th},
	{NOTE_A3, time_8th},
	{REST, time_16th},
	{NOTE_GS3, time_16th},
	{REST, time_16th},
	{NOTE_G3, time_8th},
	{NOTE_F3, time_16th * 2},
	{NOTE_D3, time_16th},
	{NOTE_F3, time_16th},
	{NOTE_G3, time_16th},

		// 5 (remaining part of the song)
};

void RIT_IRQHandler (void)
{
	static int currentNote = 0;
	static int ticks = 0;
	if(!isNotePlaying())
	{
		++ticks;
		if(ticks == UPTICKS)
		{
			ticks = 0;
			playNote(song[currentNote++]);
		}
	}
	
	if(currentNote == (sizeof(song) / sizeof(song[0])))
	{
		disable_RIT();
	}
	LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
}
/******************************************************************************
**                            End Of File
******************************************************************************/
