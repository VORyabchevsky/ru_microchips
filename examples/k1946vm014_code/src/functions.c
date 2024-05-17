#include <avr/io.h>
#include <util/delay.h>

void func(void)
{
    for (;;)
    {
        //asm("NOP");
        PORTD = 1 << PD7;
        _delay_ms(100);
        PORTD &= ~(1 << PD7);
        _delay_ms(100);
    }
}
