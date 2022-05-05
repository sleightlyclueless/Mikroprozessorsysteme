#include <conio.h>   // Windows spezifisch

/**
 * @brief Non blocking char read.
 * Eventally queued keyboard inputs are returned.
 *
 * Requires include #include <conio.h>. Reads char immediately without 'Enter' (tested on Windows)
 *
 * @see https://stackoverflow.com/questions/2654504/trying-to-read-keyboard-input-without-blocking-windows-c
 * @return char or status 0
 * @author stackoverflow
 * @version 2021-04-18 modified/adapted R.S. Mayer
 */
char getch_nb()
{
    char c = 0;         // init value
    if ( kbhit() ) {
       c = getch();     // read char
    }
    return c;           // return c
}

int sbit(int bytevalue, int pos)
{
    return bytevalue | (1 << pos);
}
int cbit(int bytevalue, int pos)
{
    return bytevalue &= ~(1 << pos);
}
