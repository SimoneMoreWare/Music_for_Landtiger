#include "music.h"

#include "../timer/timer.h"

void playNote(NOTE note)
{
	if(note.freq != REST)
	{
		reset_timer(0);
		init_timer(0, note.freq*AMPLIFIER*VOLUME);
		enable_timer(0);
	}
	reset_timer(1);
	init_timer(1, note.duration);
	enable_timer(1);
}

BOOL isNotePlaying(void)
{
	return ((LPC_TIM0->TCR != 0) || (LPC_TIM1->TCR != 0));
}
