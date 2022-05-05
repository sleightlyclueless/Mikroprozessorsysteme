#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

#include "util_Term_Keyb.h"     // Utitilies for terminal and Keyboard

/* TODO
   Macro MULT(a,b) für Multiplikation vervollständigen
 */
#define MULT(a,b) 42 // ist so natürlich Unfug ...

/**
 * main lab 1 suggestions
 * @author R. S. Mayer
 * @version 1.1
 * @date 2021-04-21
 */
int main()
{

    moin();
    //count();
    //setBit();
    //deleteBit();

    /*int a = 127;               // Number to manipulate

    printf("Welches Bit von 127 setzen (big endian):\n");
    printBinary(127);
    int b;
    scanf("%d", &b);
    printBinary(sbit(a, b));

    printf("\n");

    printf("Welches Bit von 127 loeschen (big endian):\n");
    printBinary(127);
    int c;
    scanf("%d", &c);
    printBinary(cbit(a, c));*/

}

void printBinary(int x) {
    for(int i=31;0<=i;i--) {
        printf("%u", (x>>i)&1);
    }
    printf("\n");
}

void count() {
    printf("Geben Sie Eingaben auf Ihrer Tastatur ein, um die ASCII Werte zu erfahren (ENTER um zu beenden)\n");
    char c;
    int counter = '0';                  // counter ASCII 0 am Anfang
    while (1) {
        c = getch_nb();			        // nonblocking read aus util_Term_Keyb (Windows)
        if (c != 0) {
            printf("%d \n", c);
            if (c == '\r') return;      // Exit loop on ENTER (ASCII 13)

            if (c == (counter += 1)) {  // ASCII 0 += 1->2->3->4
                if (counter == '4') {
                    printf( "1-2-3-4 gezaehlt!");
                    return;
                }
            } else {
                counter = '0';          // Exit and reset counter if input not given formula
            }
        }
    }
}

void moin() {
    printf( "Moin!\n" );
    printf( "Line %d: This is %s (%s) compiled on %s %s!\n",
           __LINE__, "Praktikum 1[main]", "Sebastian Zill 769544",
            __DATE__, __TIME__);

    // include <inttypes.h>
    uint8_t x8bit = 8;
    uint8_t y8bit = 15;
    printf("Dezimal: %d \n", x8bit);
    // 0: Left-padding number with 0
    // 4: Minimum number of characters
    printf("Hexadezimal: %04X \n", y8bit);
    printf("Binaer (Little Endian): ");
    printBinary(128);
    printf("\n \n");
}

void setBit() {
    int a = 53;               // Number to manipulate
    printf("Welches Bit von 53 setzen (big endian):\n");
    printBinary(53);

    int b;
    scanf("%d", &b);

    printBinary(53);
    printBinary(1 << b);// Maske mit bit an der zu manipulierenden Stelle erstellen
    printf("==========\n");

    a |= (1 << b);             // A OR Maske (also 1 an der stelle behalten oder schreiben)
    printBinary(a);
}

void deleteBit() {
    int a = 53;               // Number to manipulate
    printf("Welches Bit von 53 loeschen (big endian):\n");
    printBinary(53);

    int b;
    scanf("%d", &b);
    b = ~(1 << b);

    printBinary(53);
    printBinary(b);// A AND Komplement von Maske (00100 -> 11011)
    printf("==========\n");

    a &= b;
    printBinary(a);
}
