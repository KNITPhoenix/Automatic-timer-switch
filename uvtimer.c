#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
char r[]={0x7E,0x06,0x6D,0x4F,0x17,0x5B,0x7B,0x0E,0x7F,0x5F};
char a[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int i=0;
int j=0;
int k=0;
int f=0;	
void input()
{
	DDRD=0x00;
	DDRA=DDRB=DDRC=0xFF;
	if((PIND&0x01)==0x01)
	{
		_delay_ms(40);
		if(i==9)
		i=0;
		else
		i++;
	}
	else if((PIND&0x02)==0x02)
	{
		_delay_ms(40);
		if(j==9)
		j=0;
		else
		j++;
	}
	else if((PIND&0x04)==0x04)
	{
		_delay_ms(40);
		if(k==9)
		k=0;
		else
		k++;
	}
	PORTA=r[i];
	PORTB=r[j];
	PORTC=a[k];
}
void min_delay()
{
	f=((10*j)+k+(i*60))*1000;
	while(f>=0)
	{
		_delay_ms(1);
		f--;
	}
}
void main()
{
	DDRD=0x00;
	DDRA=DDRB=DDRC=0xFF;
	while(1)
	{
		input();
		if((PIND&0x40)==0x40)
		{
			PORTC|=0x80;
			min_delay();
			PORTC=0x00;
		}
		
	}
}