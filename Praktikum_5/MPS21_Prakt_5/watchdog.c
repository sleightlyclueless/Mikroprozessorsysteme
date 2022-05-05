#include <unistd.h>         // Use sleep, usleep (POSIX)
#include <pthread.h>        // POSIX threads
#include <signal.h>         // signals for threads
#include <time.h>           // time utilities

#include "watchdog.h"       // utility interrupt by key pressed
#include "myConfig.h"       // your individual settings

#include "infoUtil.h"           // line info utitilities
#define _FILE_  "watchdog.c"    //!< file name for macros in infoUtil.h

#define _SUS_       (10000)     //!< sleep micro(u) seconds in thread. Comment if not to be used

/**
 * @brief struct for watchdog internal configuration
 * Keyboard thread configuration
 * @date 2022-01-09
 */
typedef struct {
    pthread_t       threadID_WD;        //!< thread id watchdog
    FpISR_t         pfpISR_WD;          //!< address of watchdog ISR Timer function, init to NULL. @see FpISR_t
    // counters
    uint16_t        WD_reg;             //!< watchdog compare register
    uint16_t        WD_cnt;             //!< count WD register
    // align
    unsigned int                : 7;    //!< reserved, not used
    // states
    unsigned int    WD_init     : 1;    //!< watchdog initialized. 0: not started, 1: thread running
} sWDint_t;

static sWDint_t sWDint = {0};           //!< watchdog ctrl struct instance

/**
 * Default watchdog ISR. Action is exit(0).
 */
ISR_t watchdogDefault_ISR() {
    printf( "\n" );
    MSGF('I',"WATCHDOG fired!","watchdogDefault_ISR"); // Stack trace where function was called
    usleep( 500000 );           // wait 1/2 sec
    exit(0);                    // terminates program
}

/**
 * @brief Watchdog thread with POSIX
 * Watch on timeout.
 * @see fpISR_keyb
 *
 * Waiting with _SUS_ e.g. 10000 us = 1 ms improves performance
 * of system output, e.q. printf(...) significantly!
 * @see _SUS_
 *
 * @author R. S. Mayer
 * @date 2021-05-14
 * @version 2021-05-
 */
void *wd_Thread(void *vargp)
{
    MSGF('I',"Thread 'WD_Thread' starts ...","wd_Thread");

    clock_t start = clock() / MY_CORR_CLOCKS_PER_MS; // system clock (adapt to used system)
    clock_t ticks;
    while (1) {                         // forever ...
        // wait for next tick(s)
        while ( (ticks = (clock() / MY_CORR_CLOCKS_PER_MS - start)) == 0 ) {
#ifdef _SUS_
            usleep(_SUS_);                  // some wait
#endif // _SUS_
                                            // do nothing but wait
        }  // time elapsed
        sWDint.WD_cnt += ticks;             // just increment meanwhile elapsed time

        if ( sWDint.WD_cnt >= sWDint.WD_reg ) {     // timeout reached
            if ( sWDint.pfpISR_WD ) {       // ISR function pointer set
               (*sWDint.pfpISR_WD)();       // callback ISR
               break;                       // break loop, terminate thread
            }
        } // if timeout
        start = clock() / MY_CORR_CLOCKS_PER_MS;    // system clock (adapt to used system)
    } // end while
    MSGF('I',"... ending thread ...","wd_Thread");

    MSGF('I',"... thread terminated","wd_Thread");
    pthread_cancel(pthread_self()); // cancel this thread
    return NULL;
}


/**
 * @brief Initialization of watchdog timer
 * Uses a service routine on timeout. May be the internal default
 * or a user written service.
 *
 * Once started, watchdog cannot be stopped.
 * @see WATCHDOG_Reset()
 * @param timeout in ms
 * @author R.S. Mayer
 * @date 2022-01-09
 * @version
 */
void WATCHDOG_Initialize( uint16_t timeout ) {
    if ( sWDint.WD_init ) {
        MSGF('W',"WATCHDOG already initialized","WATCHDOG_Initialize");
        return;                                                     // stop here
    }
    // +++ initialize memory +++
//    sWDint.pfpISR_WD = (FpISR_t*) (HW_BASEADDR + ADDR_ISR_WD);    // set ISR vector address
//    if ( fpISR == 0 ) {                                 // use default ISR
        sWDint.pfpISR_WD = watchdogDefault_ISR; // register default ISR callback
//    }
//    else {                                              // user defined ISR (!= 0)
//        *(sWDint.pfpISR_WD) = fpISR;                    // register user defined ISR callback
//    }
    // +++ set values +++
    sWDint.WD_reg = timeout;    // set timeout
    sWDint.WD_cnt = 0;          // reset count
    // +++ start thread now +++
    int err;
    err = pthread_create(&sWDint.threadID_WD, NULL, wd_Thread, NULL);
    if (err != 0) {
        MSGF('E',"Thread 'wd_Thread' NOT started","WATCHDOG_Initialize");
        return;                                                     // stop here
    } else {
        MSGF('I',"Thread 'wd_Thread' started","WATCHDOG_Initialize");
    }
    sWDint.WD_init = 1;     // set initialized
    return;
}

/**
 * @brief Reset watchdog timer
 * Refresh/reset the running watchdog timer
 * @author R.S. Mayer
 * @date 2021-05-14
 * @version
 */
void WATCHDOG_Reset() {
    if (!sWDint.WD_init) {
        MSGF('W',"Watchdog not initialized, nothing to do","WATCHDOG_Reset");
        return;
    }
    sWDint.WD_cnt = 0;      // reset count
 }
