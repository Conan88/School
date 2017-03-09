#include<stdio.h>
#include<avr/io.h>
#include<util/delay.h>
#include<compat/deprecated.h>
#include<avr/interrupt.h>

int secondCount = 0;
int minuteCount = 0;
int hourCount = 0;
void setup()
{
  for(int i = 0; i < 6; i++)
  {
  	DDRB |= (1 << i);
  }
  DDRD &= ~(1 << 7);
  DDRD &= ~(1 << 6);
  DDRD &= ~(1 << 5);
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 62500;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << OCIE1A);
  sei();
}

ISR(TIMER1_COMPA_vect)
{
  secondCount++;
  if(secondCount == 3)
  {
  	PORTB |= (1 << 0);
    _delay_ms(500);
    PORTB &= ~(1 << 0);
    secondCount = 0;
    minuteCount++;
  }
  if(minuteCount == 2)
  {
    PORTB |= (1 << 1);
    _delay_ms(500);
    PORTB &= ~(1 << 1);
  	minuteCount = 0;
    hourCount++;
  }
  if(hourCount == 2)
  {
    PORTB |= (1 << 2);
    _delay_ms(500);
    PORTB &= ~(1 << 2);
  	hourCount = 0;
  }
  if(PORTD &= (1 << 7))
  {
  	PORTB |= (1 << 5);
  }
}

int main(void)
{
  setup();
  while(1)
  {
      _delay_ms(1000);
  }
}
