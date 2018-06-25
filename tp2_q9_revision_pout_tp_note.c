#include "iq.h"
#include "it.h"
#define byte unsigned char

/* variables globale */
byte *trisb = 0xf93 ;
byte *portb = 0xf81 ;
byte *trisd = 0xf95 ;
byte *portd = 0xf83 ;
byte *trisc = 0xf94;
byte *portc = 0xf82;

int i=0;
int nb=0;
int seconde = 0;
int minute = 0;

void affiche_7seg(byte, byte);

void affiche_7seg(byte val, byte num_affiche)
{
	byte tab_7seg[]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,
	0b00000111,0b01111111,0b01101111};

	if(num_affiche == 4)
	{
		*portd = 0xf7;
	}
	if(num_affiche == 3)
	{
		*portd = 0xfb;
	}
	if(num_affiche == 2)
	{
		*portd = 0xfd;
	}
	if(num_affiche == 1)
	{
		*portd = 0xfe;
	}
	*portb=tab_7seg[val];
	delayms(1);
}

void it_int0()
{
}

void it_int1()
{
}

/* interruption timer */
void it_tmr0()
{
	

}

void main(void)
{
	*trisc = 0xff;
	*trisd = 0 ;
	*trisb = 0;
	*portb = 0;
	*portd = 0xfe;
	//init_it_tmr0();

	while(1){
		affiche_7seg(seconde % 10, 1);
		affiche_7seg(seconde / 10, 2);

		seconde++;
		if (seconde >= 99)
		{
		seconde = 0;
		}

		delayms(1000);
	}
}
/************************************************/
