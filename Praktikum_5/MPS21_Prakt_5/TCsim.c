#include <unistd.h>         // Use sleep, usleep (POSIX)
#include <pthread.h>        // POSIX threads
#include <signal.h>         // signals for threads
#include <time.h>           // time utilities

#include "myConfig.h"       // your individual settings
#include "simISR.h"         // ISR typedef
#include "TCsim.h"

#include "infoUtil.h"       // line info utitilities

#define _FILE_  "TCsim.c"   //!< file name for macros in infoUtil.h

//#define _SUS_       (500)   //!< sleep micro(u) seconds in thread. Comment if not to be used
#define VERBOSE             //!< for verbose output

/**
 * @brief struct for timer counter internal configuration
 * Individual TC configuration
 * @date 2022-01-11
 */
typedef struct {
    FpISR_t         pfpISR_TC;          //!< address of watchdog ISR Timer function, init to NULL. @see FpISR_t
    // counters
    uint16_t        TC_reg;             //!< TC compare register
    uint16_t        TC_cnt;             //!< count TC register
    // capture
    uint16_t        TC_capt[2];         //!< capture registers for later use
    // status
    uint8_t         TC_sts;             //!< status: 0: not started, 1: TC active
//    // align
//    uint8_t         ;                   //!< alignment
} sTCconf_t;

/**
 * @brief struct for timer counter thread configuration
 * TC internal configuration
 * @date 2022-01-11
 */
typedef struct {
    pthread_t  threadID_TC;         //!< thread id timer counter
    // states
    uint8_t    TC_init;             //!< TC initialized. 0: not started, 1: thread running
} sTCint_t;

static sTCint_t sTCint = {0};       //!< TC thread ctrl struct instance

static sTCconf_t sTC1 = {0};        //!< TC1 ctrl struct instance
static sTCconf_t sTC2 = {0};        //!< TC2 ctrl struct instance
static sTCconf_t sTC3 = {0};        //!< TC3 ctrl struct instance

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
 * @date 2022-01-11
 */
void *tc_Thread(void *vargp)
{
    MSGF('I',"Thread 'tc_Thread' starts ...","tc_Thread");

    clock_t start = clock() / MY_CORR_CLOCKS_PER_MS; // system clock (adapt to used system)
    clock_t ticks;
    while (1) {                         // forever ...
        // check engine shall still run
        if ( !sTCint.TC_init ) {
            // terminate thread
            break;
        }
        // wait for next tick(s)
        while ( (ticks = (clock() / MY_CORR_CLOCKS_PER_MS - start)) == 0 ) {
#ifdef _SUS_
            usleep(_SUS_);                  // some wait
#endif // _SUS_                                            // do nothing but wait
        }  // time elapsed

        /* handle timer(s) */
        // TC 1
        if (sTC1.TC_sts) {  // timer 1 active
            sTC1.TC_cnt += ticks;
            if ( sTC1.TC_cnt >= sTC1.TC_reg ) { // counter reaches register
                (*sTC1.pfpISR_TC)();            // call ISR
                sTC1.TC_cnt = 0;                // reset counter
            }
        }
        // TC 2
        if (sTC2.TC_sts) {  // timer 1 active
            sTC2.TC_cnt += ticks;
            if ( sTC2.TC_cnt >= sTC2.TC_reg ) { // counter reaches register
                (*sTC2.pfpISR_TC)();            // call ISR
                sTC2.TC_cnt = 0;                // reset counter
            }
        }
        // TC 3
        if (sTC3.TC_sts) {  // timer 1 active
            sTC3.TC_cnt += ticks;
            if ( sTC3.TC_cnt >= sTC3.TC_reg ) { // counter reaches register
                (*sTC3.pfpISR_TC)();            // call ISR
                sTC3.TC_cnt = 0;                // reset counter
            }
        }

        start = clock() / MY_CORR_CLOCKS_PER_MS;    // system clock (adapt to used system)
    } // end while

    /* shutdown thread */
    MSGF('I',"... ending thread ...","tc_Thread");
    MSGF('I',"... thread terminated","tc_Thread");
    pthread_cancel(pthread_self()); // cancel this thread
    return NULL;
}

/** @brief start TC engine
 * Start timer counter engine thread
 */
void TCengine_start() {
    if ( sTCint.TC_init ) {
        MSGF('W',"TCengine already initialized","TCengine_start");
        return;                                                     // stop here
    }

    // +++ start thread +++
    int err;
    err = pthread_create(&sTCint.threadID_TC, NULL, tc_Thread, NULL);
    if (err != 0) {
        MSGF('E',"Thread 'tc_Thread' NOT started","TCengine_start");
        return;                                                     // stop here
    } else {
#ifdef VERBOSE
        MSGF('I',"Thread 'tc_Thread' started","TCengine_start");
#endif // VERBOSE
    }
    sTCint.TC_init = 1;     // set initialized
}

/** @brief stop TC engine
 * Stop timer counter engine thread. Stops all timer counters.
 */
void TCengine_stop() {
    if (!sTCint.TC_init) {
        MSGF('W',"Thread 'tc_Thread' not running (terminated)","TCengine_stop");
    }
    else {
#ifdef VERBOSE
        MSGF('I',"Terminating thread 'tc_Thread' ...","TCengine_stop");
#endif // VERBOSE
    sTCint.TC_init = 0;
    }
}

/** @brief config TC1
 * Configuration of TC1
 * @param fpISR pointer to ISR
 * @param tc timer register 0 < tc <= TC_MAX_COUNT
 */
void TC1config( FpISR_t fpISR, uint16_t tc) {
    if ( fpISR != 0 ) {         // check pointer
        sTC1.pfpISR_TC = fpISR;
    }
    else {
        MSGF('E',"Null pointer to ISR","TC1config");
        return;                 // leave function
    }

    if ( (tc == 0) || (tc > TC_MAX_COUNT) ) {         // check pointer
        MSGF('E',"tc register not within limits","TC1config");
        return;                 // leave function
    }
    else {
       sTC1.TC_reg = tc;
    }

    sTC1.TC_sts = 1;            // TC successfully initialized
#ifdef VERBOSE
        MSGF('I',"TC1 successfully initilaized","TC1config");
#endif // VERBOSE
}

/** @brief config TC2
 * Configuration of TC2
 * @param fpISR pointer to ISR
 * @param tc timer register 0 < tc <= TC_MAX_COUNT
 */
void TC2config( FpISR_t fpISR, uint16_t tc) {
    if ( fpISR != 0 ) {         // check pointer
        sTC2.pfpISR_TC = fpISR;
    }
    else {
        MSGF('E',"Null pointer to ISR","TC2config");
        return;                 // leave function
    }

    if ( (tc == 0) || (tc > TC_MAX_COUNT) ) {         // check pointer
        MSGF('E',"tc register not within limits","TC2config");
        return;                 // leave function
    }
    else {
       sTC2.TC_reg = tc;
    }

    sTC2.TC_sts = 1;            // TC successfully initialized
#ifdef VERBOSE
        MSGF('I',"TC2 successfully initilaized","TC2config");
#endif // VERBOSE
}

/** @brief config TC3
 * Configuration of TC3
 * @param fpISR pointer to ISR
 * @param tc timer register 0 < tc <= TC_MAX_COUNT
 */
void TC3config( FpISR_t fpISR, uint16_t tc) {
    if ( fpISR != 0 ) {         // check pointer
        sTC3.pfpISR_TC = fpISR;
    }
    else {
        MSGF('E',"Null pointer to ISR","TC3config");
        return;                 // leave function
    }

    if ( (tc == 0) || (tc > TC_MAX_COUNT) ) {         // check pointer
        MSGF('E',"tc register not within limits","TC3config");
        return;                 // leave function
    }
    else {
       sTC3.TC_reg = tc;
    }

    sTC3.TC_sts = 1;            // TC successfully initialized
#ifdef VERBOSE
        MSGF('I',"TC3 successfully initilaized","TC3config");
#endif // VERBOSE
}

/**
 * @brief Stop TC1
 * Stop TC1, disables handling in TC engine. Keeps previous configuration.
 */
void TC1stop() {
    sTC1.TC_sts = 0;
}

/**
 * @brief Stop TC2
 * Stop TC2, disables handling in TC engine. Keeps previous configuration.
 */
void TC2stop() {
    sTC2.TC_sts = 0;
}

/**
 * @brief Stop TC3
 * Stop TC3, disables handling in TC engine. Keeps previous configuration.
 */
void TC3stop() {
    sTC3.TC_sts = 0;
}
