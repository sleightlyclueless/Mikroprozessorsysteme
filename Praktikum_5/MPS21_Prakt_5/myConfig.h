#ifndef MYCONFIG_H_INCLUDED
#define MYCONFIG_H_INCLUDED

/*
 * +++ Add/modify setting individual to your system +++
 */

/**
 * Correction clocks per milliseconds from <time.h>. Must be int and >=1.
 * Adaptation may be needed for systems other than on Windows with
 * clocks faster than 1000/s.
 */
//#define MY_CORR_CLOCKS_PER_MS    (4000/CLOCKS_PER_SEC)      // other
#define MY_CORR_CLOCKS_PER_MS (1)    // Setting for Windows (LINUX should be 1000 -> ms)


#define _AUTHOR_ "Sebastian Zill | 769544, Jörg Quick | 762025"        //!< define here YOUR name(s)

#endif // MYCONFIG_H_INCLUDED
