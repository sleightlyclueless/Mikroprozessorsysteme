#include <stdio.h>
#define LED_ON  (0u)                // LED on (active low)
#define LED_OFF (1u)                // LED off (active low)

uint8_t itoLED(int i)
{
    if(i == 0)
        return LED_OFF;
    return LED_ON;
}