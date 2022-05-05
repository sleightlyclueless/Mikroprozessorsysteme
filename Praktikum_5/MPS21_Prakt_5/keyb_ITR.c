#include <unistd.h>     // Use sleep, usleep (POSIX)
//#include <stdint.h>     // GNU integer definitions
#include <pthread.h>    // POSIX threads
#include <signal.h>     // signals for threads
#include <time.h>       // time utilities
//#include <conio.h>      // Windows specific keyboard read, getch()

#include "keyb_ITR.h"   // utility interrupt by key pressed

#include "infoUtil.h"           // line info utitilities
#define _FILE_  "keyb_ITR.c"    //!< file name for macros in infoUtil.h

#define _SUS_       (1000)  //!< sleep micro(u) seconds in threads. Comment if not to be used

/* local variables */
static FpISR_t fpISR_keyb = 0;      //!< address of ISR for keyboard handling, init to NULL. @see FpISR_t
static pthread_t threadIDkeyboard;  //!< thread id keyboard_Thread
static uint8_t KEYB_state = 0;      //!< thread state. 0: not started or to be terminated, 1: started and running
//char _Keyb_c_ = 0;                  //!< char read when keyboard fired. Need to be reseted by user.

/**
 * @brief Register ISR function keyboard
 * @param fpISR pointer to ISR function
 */
void regISR_Keyboard( FpISR_t fpISR ) {
    fpISR_keyb = fpISR;
}

/**
 * @brief Keyboard watch thread with POSIX
 * Watch on kbhit().
 * @see fpISR_keyb
 * @author R. S. Mayer
 * @date 2022-01-09
 */
void *keyboard_Thread(void *vargp)
{
    while (1) {                     // forever ...
#ifdef _SUS_
        usleep(_SUS_);              // some wait
#endif // _SUS_
        if (!KEYB_state)            // to be terminated
            break;                  // end loop an terminate
        if ( kbhit() ) {
            if ( fpISR_keyb ) {     // ISR function pointer set
                (*fpISR_keyb)();    // callback ISR
            }
//            else {                // temporary implementation
//                _Keyb_c_ = getch(); // read char
//            }
        } // end kbhit
    } // end while
    MSGF('I',"Thread terminating","keyboard_Thread");
    pthread_cancel(pthread_self()); // cancel this thread
    return NULL;
}

/**
 * @brief Start Keyboard thread
 * Starts the POSIX thread.
 */
void Start_Keyboard() {
    if ( fpISR_keyb == 0 ) {
        MSGF('E',"No ISR registered! Not started","Start_Keyboard");
        return;
    }
    int err;
    err = pthread_create(&threadIDkeyboard, NULL, keyboard_Thread, NULL);
    if (err != 0) {
        MSGF('E',"Thread 'keyboard_Thread' NOT started","Start_Keyboard");
    } else {
        MSGF('I',"Thread 'keyboard_Thread' started","Start_Keyboard");
    }
    KEYB_state = 1;     // set state flag running
}

/**
 * @brief Stop Keyboard thread
 * Stops the POSIX thread
 */
void Stop_Keyboard() {
    KEYB_state = 0;     // to be terminated
    MSGF('I',"Thread 'keyboard_Thread' stopped","Stop_Keyboard");
}


