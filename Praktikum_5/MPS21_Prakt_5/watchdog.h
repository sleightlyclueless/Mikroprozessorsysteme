#ifndef WATCHDOG_H_INCLUDED
#define WATCHDOG_H_INCLUDED

#include <stdint.h>     // GNU integer definitions
#include "simISR.h"     // simulation of interrupt services

#define WDT_ACTION_DEFAULT  (0)     //!< use default watchdog action on timeout

#define WDT_TIMEOUT_500     (500)   //!< watchdog timeout 500 ms
#define WDT_TIMEOUT_1000    (1000)  //!< watchdog timeout 1 s
#define WDT_TIMEOUT_2000    (2000)  //!< watchdog timeout 2 s
#define WDT_TIMEOUT_4000    (4000)  //!< watchdog timeout 4 s
#define WDT_TIMEOUT_8000    (8000)  //!< watchdog timeout 8 s


/* +++ forward declarations +++ */

/** @brief Initialization of watchdog timer */
void WATCHDOG_Initialize( uint16_t timeout );

/** @brief Reset watchdog timer */
void WATCHDOG_Reset();

// don't add code behind this line
#endif // WATCHDOG_H_INCLUDED
