#ifndef KEYB_ITR_H_INCLUDED
#define KEYB_ITR_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>     // GNU integer definitions
//#include <stdio.h>
#include <conio.h>      // Windows specific keyboard read, getch()

#include "simISR.h"     // simulation of interrupt services

/* +++ declarations +++ */

extern char _Keyb_c_;   //!< keyboard char read only if no ISR registered

/* +++ forward declarations +++ */

/** @brief Register ISR function keyboard */
void regISR_Keyboard( FpISR_t fpISR );

/** @brief Keyboard watch thread with POSIX */
//void *keyboard_Thread(void *vargp);

/** @brief Start Keyboard thread */
void Start_Keyboard();

/** @brief Stop Keyboard thread */
void Stop_Keyboard();

// don't add code behind this line
#endif // KEYB_ITR_H_INCLUDED
