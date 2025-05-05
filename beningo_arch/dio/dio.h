/**
 * @file    dio.h
 * @author  Gabriel Ocaga (you@domain.com)
 * @brief   The interface definition for the dio.
 *          This is the header fiule for the definition of the interface for
 *          a digital input/output peripheral on a standard microcontroller. 
 * @version 1.x.x
 * @date    2025-05-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef DIO_H_
#define DIO_H_

#include <stdint.h>
#include "dio_config.h"
#include "constants.h"   //!< For HIGH, LOW, etc

#ifdef __cplusplus
extern "C"{
#endif

void DIO_init(const DIO_Config_e* const config);
DIO_PinState_e DIO_readChannel(DIO_Channel_e channel);
void DIO_writeChannel(DIO_Channel_e channel, DIO_PinState_e state);
void DIO_toggleChannel(DIO_Channel_e channel);
void DIO_writeChannel(uint32_t address, TYPE value);
TYPE DIO_readRegister(uint32_t address);
void DIO_callbackRegister(DIO_Callback_t function, TYPE (*CallbackFunction)(type));

#ifdef __cplusplus
} // extern "C"
#endif

#endif //DIO_H_