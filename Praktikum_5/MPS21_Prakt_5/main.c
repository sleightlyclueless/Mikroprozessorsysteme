#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>             // Use sleep, usleep (POSIX)
#include <stdint.h>             // GNU integer definitions

#include <time.h>               // time utilities

#include "myConfig.h"           // your individual settings
#include "simISR.h"             // simulation of interrupt services
#include "keyb_ITR.h"           // keyboard interrupt (simulated)
#include "TCsim.h"              // Timer interrupt (simulated)
#include "infoUtil.h"           // line info utitilities
#include "schedule.h"           // test: simple scheduler
#include "watchdog.h"           // test: simple watchdog

#define _FILE_  "main.c"        //!< file name for macros in infoUtil.h
#define MAX_TASKS 3             //!< Maximum of tasks to be handled by scheduler in taskList
#define SCHEDULE_TICKS 100      //!< Scheduler führt schneller aus (alle x ms)


static volatile char cKB = 0;   //!< character read in @see myKeyboard_ISR
/**
 * @brief Service Routine for simulated interrupt
 * ISR for Keyboard
 */
ISR_t myKeyboard_ISR() {
    cKB = getch();               //!< read from keyboard
}

// >>> TODO <<<
/*
 * +++ Tasks for scheduling +++
 */
task_t task1( uint32_t input ) {
    printf( "[Task 1], param: %d\n ", input + 1);
    return SUCCESS;
}
task_t task2( uint32_t input ) {
    printf( "[Task 2], param: %d\n ", input + 1);
    return SUCCESS;
}
task_t task3( uint32_t input ) {
    WATCHDOG_Reset();
    printf( "[Task 3], Watchdog resetted!\n");
    return SUCCESS;
}

/*
 * List of tasks to be scheduled.
 * Period of each task can freely be configured
 */
sTskLst_t* taskList[MAX_TASKS];

/**
 * Schedule after each timer event.
 * Set waiting task(s) to ready, when period is reached
 * @see sTskLst_t
 * @attention Muss implementiert werden!
 */
void schedule() {
    // Loop through todos
    for (int i = 0; i< MAX_TASKS; i++)
    {
        if (taskList[i] != NULL && taskList[i]->sts == WAIT)
        {
            taskList[i]->elapsed += 100;
            if (taskList[i]->elapsed >= taskList[i]->period)
            {
                // Start task: Set task as ready
                taskList[i]->sts = RDY;
            }
        }
    }
}

// >>> TODO <<<
/**
 * Dispatch (execute) ready task in scheduler
 * @see sTskLst_t
 * @attention Muss implementiert werden!
 */
void dispatch() {
    // >>> TODO <<<
    // Loop through todos
    for (int i = 0; i< MAX_TASKS; i++)
    {
        if (taskList[i] != NULL && taskList[i]->sts == RDY)
        {
            // set status to run and run
            taskList[i]->sts = RUN;
            (*taskList[i]->fpTask)(i);

            // reset attributes
            taskList[i]->sts = WAIT;
            taskList[i]->elapsed = 0;
        }
    }
}

// timer called every 10ms
static uint8_t bIsrTC1 = 0;             //!< flag for ISR TC1 timer
/**
 * @brief Service Routine for simulated interrupt
 * ISR for TC 2
 */
ISR_t myTC1_ISR() {
    schedule();                         // >>> TODO <<< implementieren!
    static int ts;
    ts++;
    if ( (ts % 10) == 0 )
        printf( "." );
}

/**
 * @brief Template MPS, Termin 4 mit volatile, Scheduler und Watchdog
 * @author R. S. Mayer
 * @date 2021-06-02
 */
int main()
{
    SWINFO( "MPS21-Prakt_5", _AUTHOR_ );     // info about project
    MSGF( 'I', "Starting ...", "main" );    // a line info

    /*
     * +++ initialisation +++
     */
    // keyboard
    regISR_Keyboard( myKeyboard_ISR );  // register Keyboard interrupt
    Start_Keyboard();                   // start

    // Timer for Scheduler
    TC1config( myTC1_ISR, SCHEDULE_TICKS );        // config timer 1, ISR, 100 ms
    TCengine_start();                   // start simulated timer

    // >>> TODO <<<
    // tasklist
    for (int i = 0; i< MAX_TASKS; i++)
    {
        taskList[i] = NULL;
    }
    // tmp: fill tasklist
    // memory allocate -> new element (mdel = delete)
    sTskLst_t* myTask1 = malloc(sizeof(sTskLst_t));
    sTskLst_t* myTask2 = malloc(sizeof(sTskLst_t));
    sTskLst_t* myTask3 = malloc(sizeof(sTskLst_t));
    // give attributes
    myTask1->elapsed = 0;
    myTask1->fpTask = &task1;
    myTask1->period = 1000;
    myTask1->sts = WAIT;

    myTask2->elapsed = 0;
    myTask2->fpTask = &task2;
    myTask2->period = 400;
    myTask2->sts = WAIT;

    myTask3->elapsed = 0;
    myTask3->fpTask = &task3;
    myTask3->period = 5000;  // --> Reset watchdog after 5 seconds
    myTask3->sts = WAIT;
    // fill tasklist
    taskList[0] = myTask1;
    taskList[1] = myTask2;
    taskList[2] = myTask3;


    MSGF( 'I', ">>> please press 'h' or 'H' for Help <<<", "main" );  // a line info

    printf( "\n" );     // clear line
    MSGF( 'I', "Start Watchdog >>>Use key 'r' or program dies within 8 sec!<<<", "main" );  // a line info
    printf(    "                  ------------------------------------------------\n\n" );     // clear line
    WATCHDOG_Initialize( WDT_TIMEOUT_8000 );   // activate watchdog

    /*
     *  +++ endless loop +++
     */
    uint8_t run = 1;
    do {                                // +++ endless loop
        /* +++ handle tc interrupts +++ */
        // (if any)

        /* +++ handle keyboard +++      */
        if (cKB) {
            switch (cKB) {
                case 'r':               // reset watchdog
                    WATCHDOG_Reset();
                    MSGF( 'I', "Watchdog reseted", "main" );    // a line info
                    break;
                case 'q':               // quit
                    run = 0;
                    break;
                case 'h':               // help
                case 'H':               // help
                    printf("\nHelp:\n\tH,h: help\n\tq: quit\n\tr: WD reset\n");
                    break;
                default:
                    printf("[%c]", cKB);
                    break;
            }
            cKB = 0;                    // don't forget!
        } // if cKB

        /* +++ dispatch scheduled tasks +++ */
        dispatch();                     // >>> TODO <<< implement scheduler!

    } while (run);                      // --- end loop ---
    return 0;
}
