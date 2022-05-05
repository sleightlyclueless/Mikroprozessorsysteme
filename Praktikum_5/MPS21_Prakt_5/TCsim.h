#ifndef TCSIM_H_INCLUDED
#define TCSIM_H_INCLUDED

#define TC_MAX_COUNT            (65000)     //!< TC maximum count in capture mode (max 2^16 - 3)

/* forward declarations */
/** @brief start TC engine */
void TCengine_start();

/** @brief stop TC engine */
void TCengine_stop();

/** @brief config TC1 */
void TC1config( FpISR_t fpISR, uint16_t tc);

/** @brief config TC2 */
void TC2config( FpISR_t fpISR, uint16_t tc);

/** @brief config TC3 */
void TC3config( FpISR_t fpISR, uint16_t tc);

/** @brief Stop TC1 */
void TC1stop();

/** @brief Stop TC2 */
void TC2stop();

/** @brief Stop TC3 */
void TC3stop();

#endif // TCSIM_H_INCLUDED
