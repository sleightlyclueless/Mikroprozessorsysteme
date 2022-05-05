#ifndef SIMISR_H_INCLUDED
#define SIMISR_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>     // GNU integer definitions

/**
 * @brief function typedef ISR
 * Type of Interrupt Service Routine (ISR) as simulation for callback on event.
 * For pointer to function @see FpISR_t
 */
typedef void ISR_t;

typedef ISR_t(*FpISR_t)();  //!< function pointer to ISR_t (ATTENTION: 64bit!). @see ISR_t

// don't add code behind this line
#endif // SIMISR_H_INCLUDED
