// =============================== INCLUDES ===============================
#include "project.h"
#include "HAL.h"
#include <stdio.h>                              // string operations

// =============================== DEFINES  ===============================
#define _PROJECT_NAME   "MPS21_Prakt_4"         // project name
#define _DEVICE_NAME    "FreeSoC2"              // board or device type
#define _PROCESSOR      "PSoC 5LP"              // processor type
#define _VERSION_NR     "Ver. 1.1"              // version number. Please update
#define _AUTHOR_        "Sebastian Zill"
#define _COMPANY        "Template MPS 4"

// Build string to print buffer
#define _VERSTR_       (_PROJECT_NAME" - "_DEVICE_NAME", "_PROCESSOR" - "_VERSION_NR"\n\r"\
_AUTHOR_", "__DATE__" "__TIME__)

#define BUFFER_SIZE 128                         // string output buffer size for sprintf
static char buffer[BUFFER_SIZE];                // buffer (global) for sprintf


// ============================== INTERRUPTS ==============================
/** 
 * UART RX interrupt service routine.
 *
 * Collect a characters from UART into a global input variable.
 * @see cRx
 */
static char cRx = 0;                            // character from UART, visible within main.c
CY_ISR( MyIsrUartRX )
{
    cRx = UART_GetChar();                       // read and set char
}

/** 
 * Interrupt isr_CWSN for button Pin_CWSN interrupt service routine.
 *
 * @see fCWEW_Isr
 */
static uint8_t fCWEW_Isr = 0;                   // flag CW EW button isr, visible within main.c
CY_ISR( MyIsrCWEW )
{
    Pin_CWEW_ClearInterrupt();                  // clear interrupt first
    if (fCWEW_Isr != 1)
        fCWEW_Isr = 1;                          // set flag
}

/** 
 * Application clock interrupt service routine for isr_Clk every second
 *
 * @see fClock
 */
static uint8_t  fsClock = 0;                    // s flag
static uint32_t count_ms = 0;                   // ms count since start
CY_ISR( IsrAppClk )
{
    count_ms++;                                 // increment ms timestamp
    if ( (count_ms % 1000) == 0 )               // next 1 s reached
       fsClock = 1;                             // set flag
}




// ==========================================================================================
// =============================== START TRAFFIC LIGHTS LOGIC ===============================
// ==========================================================================================
static int state = 0;
// matrix (optimized)
// ns-r, ns-y, ns-g, w-r, w-y, w-g, fns, fw
// NOTE: First number obsolete
static int States[][8] =
{
    {1,0,0,1,0,0,0,0}, //0,6    0
    {1,1,0,1,0,0,0,0}, //1      1
    {0,0,1,1,0,0,1,0}, //2,3,4  2
    {0,1,0,1,0,0,0,0}, //5      3
    {1,0,0,1,1,0,0,0}, //7      4
    {1,0,0,0,0,1,0,1}, //8,9    5
    {1,0,0,0,1,0,0,0}, //10     6
};


// get array of 8 independent light states (on/off = 1/0) as argument and set traffic lights accordingly
void setLightsFromArray(int *arr)
{
    // traffic lights north/south
    Pin_N_R_Write(itoLED(arr[0]));
    Pin_N_Y_Write(itoLED(arr[1]));
    Pin_N_G_Write(itoLED(arr[2]));
    
    Pin_S_R_Write(itoLED(arr[0]));
    Pin_S_Y_Write(itoLED(arr[1]));
    Pin_S_G_Write(itoLED(arr[2]));
    
    // traffic lights west
    Pin_W_R_Write(itoLED(arr[3]));
    Pin_W_Y_Write(itoLED(arr[4]));
    Pin_W_G_Write(itoLED(arr[5]));
    
    // pedestrian lights north/south and west
    Pin_S_CW_Write(itoLED(arr[6]));
    Pin_E_CW_Write(itoLED(arr[7]));
}

// parse intersection-state and pass led-state array to changeLightsFunction
void handleIntersection()
{
    // rotate through the 10 (optimized to 6 array lines) intersection-states and switch traffic leds from according state-array 
    switch (state)
    {
        case 0:
        case 6:
            setLightsFromArray(States[0]);
            break;
        
        case 1:
            setLightsFromArray(States[1]);
            break;
        
        case 2:
        case 3:
        case 4:
            setLightsFromArray(States[2]);
            if ( fCWEW_Isr )                    // pedestriant wants to cross
            {
                UART_PutString("\n\rPassengers NS pass!\n");
                UART_PutChar(7);
                for(int loop=0;loop<10000000;loop++);
                fCWEW_Isr = 0;
            }
            break;
        
        case 5:
            setLightsFromArray(States[3]);
            break;
        
        case 7:
            setLightsFromArray(States[4]);
            break;
        
        case 8:
        case 9:
            setLightsFromArray(States[5]);
            if ( fCWEW_Isr )                    // pedestriant wants to cross
            {
                UART_PutString("\n\rPassengers W pass!\n");
                UART_PutChar(7);
                for(int loop=0;loop<10000000;loop++);
                fCWEW_Isr = 0;
            }
            break;
        
        case 10:
            setLightsFromArray(States[6]);
            break;
        
        default:
        UART_PutString("Something went wrong.");
    }

    // when done increase intersection-state for next iteration (until 10 and restart/rotate from start state)
    state++;
    if (state > 10)
        state = 0;
}




// ==============================================================================
// =============================== START Programm ===============================
// ==============================================================================
int main(void)
{
    /* initialize and start UART, register ISR */
    UART_Start();                               // start UART
    isr_UART_RX_StartEx( MyIsrUartRX );         // register ISR, enable itr uart
    
    /* initialize PWM */
    PWM_Start();                                // start PWM

    /* initialize and start MyIsrCWEW, register ISR */
    isr_CWEW_StartEx( MyIsrCWEW );              // register CWEW itr
    Pin_CWEW_ClearInterrupt();                  // clear eventual interrupt
    isr_CWEW_ClearPending();                    // clear eventual pending interrupt
    
    /* initialize CLK */
    isr_Clk_StartEx( IsrAppClk );               // register application clock
    
    /* enable global interrupts. */
    CyGlobalIntEnable;

    
    /* welcome and info text output */
    sprintf( buffer, "\n\rWelcome! %s\n\r", _VERSTR_);
    UART_PutString( buffer );
    


    // application loop
    for(;;)
    {
        // change state of intersection every second from CLK interrupt
        if ( fsClock )
        {
            fsClock = 0;                        // reset clock interrupt for the next second
            handleIntersection();
        }

        // char inputs apart from application loop
        if ( cRx ) {
            char c = cRx;                       // copy char to variable
            cRx = 0;                            // reset char interrupt flag to instantly continue with traffic lights

            // +++ Menuesteuerung +++
            switch ( c ) {
                // Software reset, startet Programm neu
                case 'q':
                case 'Q':
                    CySoftwareReset();
                    break;

                case 'h':
                case 'H':
                    UART_PutString( "\n\rHelp:\n\r\
                                    \th,H: help\n\r\
                                    \tq,Q: software reset\n\r" );
                    break;

                case '+':
                    UART_PutString( "\n\rBrighter!\n");
                    PWM_WriteCompare1 ( PWM_ReadCompare1() - 50 );
                    PWM_WriteCompare2 ( PWM_ReadCompare2() - 50 );
                    break;

                case '-':
                    UART_PutString( "\n\rDarker!\n");
                    PWM_WriteCompare1 ( PWM_ReadCompare1() + 50 );
                    PWM_WriteCompare2 ( PWM_ReadCompare2() + 50 );
                    break;

                

                default:
                    UART_PutChar( c );
                    break;
            }
        }              
    }
}
