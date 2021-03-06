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
	if(x > 448){

	//b = (x & 0x0FF);
	//d = (x >> 8);
	//PORTB = b;
		d = 0x02;
		PORTD = d;
	}
	else{
		//PORTB = 0x00;
		PORTD = 0x00;
	}

    }
    return 1;
}
