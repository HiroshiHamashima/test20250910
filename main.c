#include <xc.h>

// CONFIG
#pragma config FOSC = INTRCCLK  // Internal oscillator, CLKOUT function on GP4/OSC2/CLKOUT
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable (PWRT enabled)
#pragma config MCLRE = OFF      // GP3/MCLR pin function is digital input, MCLR internally tied to VDD
#pragma config CP = OFF         // Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (BOR enabled)
#pragma config IESO = OFF       // Internal External Switchover mode is disabled
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor is disabled

#define _XTAL_FREQ 4000000 // 4MHz internal oscillator

void main(void)
{
    // Set GP0 as output
    TRISIO0 = 0; // GP0 output
    // Optionally, set other unused pins as input
    // TRISIO = 0b00000001; // Only GP0 output, rest input

    // Disable analog functions (if needed)
    ANSEL = 0; // All pins digital

    while(1)
    {
        // Turn LED ON
        GP0 = 1;
        __delay_ms(1000); // 1 second delay

        // Turn LED OFF
        GP0 = 0;
        __delay_ms(1000); // 1 second delay
    }
}