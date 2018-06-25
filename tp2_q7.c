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

void affiche_7seg(byte);

void affiche_7seg(byte val)
{
    byte
    tab_7seg[]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,
    0b00000111,0b01111111,0b01101111};
    *portb=tab_7seg[val];
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
    i++;
    affiche_7seg(seconde % 10);
    if ((i % 10) == 0) seconde ++;
}

void main(void)
{
    *trisc = 0xff;
    *trisd = 0 ;
    *trisb = 0;
    *portb = 0;
    //*portd = 0xfe;
    *portd = 0xfd;
    init_it_tmr0();
    while(1){
    }
}
/************************************************/
