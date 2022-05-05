#include "project.h"
#include <stdio.h>      // sprintf operations for buffer
#include <stdbool.h>    // usage of bool values

#define _PROJECT_NAME   "MPS21_Prakt_2" // Project name
#define _VERSION_NR     "ver. 1.2"      // Version number. Please update
#define _PROCESSOR      "PSoC 5LP"      // Processor type
#define _DEVICE_NAME    "FreeSoC2"      // Board or device type
#define _AUTHOR         "Sebastian Zill"// Author
#define _MENU           "Instructions: \n\r Press x to quit! \n\r Press g to toggle green light \n\r Press y to toggle yellow light \n\r Press r to toggle red light \n\r Press the botton(s) on the very bottom to toggle white light \n\r"

// build string for display
#define _VERSTR       (_PROJECT_NAME" ("_VERSION_NR") - "_DEVICE_NAME", "_PROCESSOR", \n\r"\
_AUTHOR", "__DATE__" "__TIME__)

// Macros for I/O
#define LED_ON  (0u)                    //!< LED on (active low)
#define LED_OFF (1u)                    //!< LED off (active low)

// string buffer for output
#define BUFFER_SIZE 128                 //!< string output buffer size for sprintf
static char buffer[BUFFER_SIZE];        //!< buffer (global) for sprintf


int main(void)
{
    // initialize
    UART_Start();                       // start UART
    CyGlobalIntEnable;                  // enable global interrupts

    // welcome and info text
    sprintf( buffer, "\n\rWelcome! %s\n\r %s", _VERSTR, _MENU);   // format butter
    UART_PutString( buffer );                                     // print buffer to UART
    
    // declarations
    uint8_t chr = 0;                    // chars from UART


    /* +++ application loop - iterated permanently +++ */
    for(;;)
    {
        /* +++ get uart char +++ */
        chr = UART_GetChar();           //  = 0: while no input
                                        // != 0: got input

        // +++ Evaluate chr +++ 
        if ( chr != 0 )                 // gotten chr input
        {
            switch (chr)
            {
                case 'x':
                    UART_PutString( "... Bye! \n\r" );
                    return 0;
                
                case 'g':
                    UART_PutString( "Green light toggled! \n\r" );
                    if ( Pin_N_G_Read() == LED_OFF )
                        Pin_N_G_Write( LED_ON );
                    else
                        Pin_N_G_Write( LED_OFF );
                    break;

                case 'y':
                    UART_PutString( "Yellow light toggled! \n\r" );
                    if ( Pin_N_Y_Read() == LED_OFF )
                        Pin_N_Y_Write( LED_ON );
                    else
                        Pin_N_Y_Write( LED_OFF );
                    break;

                case 'r':
                    UART_PutString( "Red light toggled! \n\r" );
                    if ( Pin_N_R_Read() == LED_OFF )
                        Pin_N_R_Write( LED_ON );
                    else
                        Pin_N_R_Write( LED_OFF );
                    break;
                
                default:
                    sprintf( buffer, "erwarte ein <x>, <g>, <y> oder <r>, aber <%c> wurde eingegeben\n\r", chr );
                    UART_PutString( buffer );
                    break;
            }
            chr = 0;                    // reset chr for ISR loop
        }


        // TASK 5
        // +++ evaluate button CWEW +++ 
        bool pressed = false;
        if ( Pin_CWEW_Read() == 0 )     // if button pressed
        {
            if(!pressed)                // and not pressed before (prellen)
            {
                // toggle led accordingly
                if ( Pin_E_CW_Read() == LED_OFF )
                    Pin_E_CW_Write( LED_ON );
                else
                    Pin_E_CW_Write( LED_OFF );
                pressed = true;         // set pressed true to prevent double activating
            }
        }
        else if( Pin_CWEW_Read() != 0 ) // if button released
        {                               // and pressed still true,
            if(pressed)
                pressed = false;        // reset to false
        }


        // TASK 6
        // +++ LED blinken lassen, warten mit Schleife +++
        volatile uint32_t loop;          // works with DEBUG, not with RELEASE
        // why???
        // loop not used initially - compiler "optimizing" it away
        // what does 'volatile' do?
        // volatile tells the compiler not to optimize anything that has to do with the volatile variable.
        Pin_N_R_Write( LED_ON );                    // turn on
        for ( loop = 0; loop < 1000000; loop++ );   // wait with loop
        Pin_N_R_Write( LED_OFF );                   // turn off
        for ( loop = 0; loop < 1000000; loop++ );   // wait with loop
        
    } // end for
    
} // end main