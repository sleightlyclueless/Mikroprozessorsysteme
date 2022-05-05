#ifndef SCHEDULE_H_INCLUDED
#define SCHEDULE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>     // GNU integer definitions

/**
 * @brief Function typedef task_t
 * Type of task for scheduler.
 * For pointer to function @see FpISR_t
 */
typedef uint32_t task_t;

typedef task_t(*FpTsk_t)(uint32_t);     //!< function pointer to task_t (ATTENTION: 64bit!). @see task_t
                                        // typedef task_t functionname(arguments)?

/**
 * Possible task stati. waiting, ready-to-run, running, terminated
 */
enum eSts{
    WAIT,       //!< waiting for period time elapsed -> RDY
    RDY,        //!< ready for execution on next dispatch. -> RUN
    RUN,        //!< running. After -> WAIT
    TERM        //!< terminated. Currently not used
};

enum eRet { SUCCESS, WARN, ERROR } ;    //!< possible task return stati.

/**
 * @brief Typedef for simple task list
 * Simple list for tasks to be scheduled and dispatched.
 */
typedef struct {
    FpTsk_t         fpTask;             //!< pointer to task function
    enum eSts            sts;           //!< task status. @see eSts
    uint32_t        period;             //!< scheduling period, e.g. in ms
    uint32_t        elapsed;            //!< elapsed time to period and next execution
} sTskLst_t;

#endif // SCHEDULE_H_INCLUDED
