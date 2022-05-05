/* ========================================
 *
 * Copyright R. Mayer, h_da, FbI, 2019
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
 */
#include "project.h"
#include "main.h"
#include <stdio.h>          // für string-Operationen wie sprintf

/*
 * Diese Definitionen ermöglichen es, 
 * einfach Informationen auf den Bildschirm zu schreiben
 */
#define _VERSION_NR     "ver. 1.0"              //!< Version number. Please update
#define _PROJECT_NAME   "MPS21_Prakt_3"         //!< Project name
#define _PROCESSOR      "PSoC 5LP"              //!< Processor type
#define _DEVICE_NAME    "FreeSoC2"              //!< Board or device type
#define _AUTHOR_        "Sebastian Zill"
#define _COMPANY        "Template MPS 3"
// Makros für LED io (wieder) definieren
#define LED_ON  (0u)                //!< LED on (active low)
#define LED_OFF (1u)                //!< LED off (active low)
/* ++++++++++++++++++++++++++++++++++
 * +++ Switche für Musterlösungen +++ 
 * ++++++++++++++++++++++++++++++++++ */

// String für die Anzeige zusammenbauen
#define _VERSTR_       (_PROJECT_NAME", "_DEVICE_NAME", "_PROCESSOR", "_VERSION_NR"\n\r"\
_AUTHOR_" ("_COMPANY"), "__DATE__" "__TIME__)

/* 
 * String Buffer für Anzeige am Bildschirm anlegen.
 * Auf die maximale Größe achten!
 */
#define BUFFER_SIZE 128             //!< string output buffer size for sprintf
static char buffer[BUFFER_SIZE];    //!< buffer (global) for sprintf

static char cRx = 0;                //!< character from UART, visible within main.c
/** 
 * UART RX interrupt service routine.
 *
 * Collect a characters from UART into a global input variable.
 * @see cRx
 */
CY_ISR( MyIsrUartRX )
{
    cRx = UART_GetChar();       // read and copy char
}

static uint8_t fCWEW_Isr = 0;   //!< flag CW EW button isr, visible within main.c
/** 
 * Interrupt isr_CWSN for button Pin_CWSN interrupt service routine.
 *
 * @see fCWEW_Isr
 */
CY_ISR( MyIsrCWEW ) // Wird bei Buttonpress ausgeführt
{
    Pin_CWEW_ClearInterrupt();  // Clear Interrupt
    fCWEW_Isr = 1;              // set flag 
}

static int clk_count = 1;
static uint8_t clk_flag = 0;
/** 
 * Application clock interrupt service routine for isr_Clk
 *
 * @see fClock
 */
CY_ISR( IsrAppClk )
{
    clk_count++;
    if (clk_count % 1000 == 0)  // Reached 1000th hz call for 1/1000sec => 1 sec passed
    {
        clk_flag = 1;
        return;
    }
    clk_flag = 0;
}


// Toggle LED
uint8_t toggleLED(uint8_t dword)
{
    if(dword == LED_ON)
        return LED_OFF;
    else
        return LED_ON;
}


/**
 * Basisprojekt mit UART mit Interrupt, User Button mit Interrupt und Statusabfrage. 
 * Pin-I/O Einfache Eingabe mit Button, Ausgabe mit LED
 * für FreeSoC2
 * 
 * @author Ralf S. Mayer
 * @date 2019-09-18
 * @version 1.0
 */
int main(void)
{
    /* Initialize and start UART, register ISR */
    UART_Start();                       // start UART
    isr_UART_RX_StartEx( MyIsrUartRX ); // register ISR, enable itr uart
                                        // Bei empfangen eines Bytes wird der UART
                                        // Interrupt ausgelöst

    /* Initialize and start MyIsrCWEW, register ISR */
    isr_CWEW_StartEx( MyIsrCWEW );      // register CWEW itr
    Pin_CWEW_ClearInterrupt();          // clear eventual interrupt
    isr_CWEW_ClearPending();            // clear eventual pending interrupt
    
    isr_Clk_StartEx( IsrAppClk );       // register application clock
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Welcome and info text Ausgabe */
    sprintf( buffer, "\n\rWelcome! %s\n\r", _VERSTR_);  // formatiert in Buffer
    UART_PutString( buffer );                           // Ausgabe auf UART

    // Applikationsschleife
    for(;;)
    {
        /* 
         * Character aus Uart ISR abfragen 
         * Beipsiel für einfache Menuesteuerung
         * Achtung: Für UART in diesem Programm ist ein zusätzlicher FTDI USB-TTL-Adapter notwendig 
         */
        if ( cRx )
        {
            char c = cRx;   // copy char
            cRx = 0;        // nicht vergessen!!! Warum? Weil der cRx nur duch system Interrupt resettet wird
            // +++ Menuesteuerung +++
            switch ( c ) 
            {
                // Software reset, startet Programm neu
                case 'q':
                case 'Q':   // fallthrough
                    CySoftwareReset();
                    break;
                case 'm':   // so könnte man etwas steuern über die Konsole
                    UART_PutString( "Menu-Beispiel: Taste 'm' gedrueckt\n\r" );
                    break;
                default:
                    UART_PutChar( c );    // Buchstabe auf Bildschirm ausgeben
                    break;
            }  // end switch          
        } // end if cRx
        
        
        // Behandlung Button-Ereignis aus ISR und LED toggle
        if ( fCWEW_Isr ) {
            Pin_E_CW_Write( toggleLED( Pin_E_CW_Read() ) );
            UART_PutChar(7);// Spiele Ton ab mit Steuerzeichen BEL (7)
            fCWEW_Isr = 0;
        }
        
        // Behandlung CLK-Ereignis jede Sekunde
        if ( clk_flag ) {
            sprintf( buffer, "Time passed: %d sec.\r", clk_count / 1000);
            UART_PutString( buffer );
        }
                
    } // end for
}

/* [] END OF FILE */
