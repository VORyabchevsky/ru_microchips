#include <avr/io.h>
#include "functions.h"

int main(void)
{
    DDRD = 1 << PD7;
    func();

    return 0;
}
