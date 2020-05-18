/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
unsigned short x;
unsigned char b;
unsigned char d;
void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}
int main(void) {
    /* Insert DDR and PORT initializations */
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
    ADC_init();
    while (1) {
	x = ADC;
	//set max = 1110000000 = 896
	//max / 2 = 111000000 = 448
	if(x < 112){
		b = 0x01;
	}
	if(x >= 112 && x < 224){
		b = 0x03;
	}
	if(x >= 224 && x < 336){
		b = 0x07;
	}
	if(x >= 336 && x < 448){
		b = 0x0F;
	}
	if(x >= 448 && x < 560){
		b = 0x1F;
	}
	if(x >= 560 && x < 672){
		b = 0x3F;
	}
	if(x >= 672 && x < 784){
		b = 0x7F;
	}
	if(x >= 784){
		b = 0xFF;
	}
	PORTB = b;

   }

    return 1;
}
