/**
 * @file    dio_config.h
 * @author  Gabrieil Ocaga (gocaga@hotmail.com)
 * @brief   This module contains interface definitions for the dio configuration
 *          This is the header file for the definition of the interface for
 *          retrieving the digital input/output configuration table. 
 * @version 1.x.x
 * @date    2025-05-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef DIO_H_
#define DIO_H_

//Includes

//Preprocessor Constants

//!< Defines the number of pins on each processor port.
#define NUMBER_OF_CHANNELS_PER_PORT    (8U)

//!< Defines the number of ports on the processor
#define NUMBER_OF_PORTS                (8U)


//Typedefs

/**
 * @brief Defines the possible states for a digital output pin.
 * 
 */
typedef enum
{
    DIO_LOW,            //!< Defines the digital state ground
    DIO_HIGH,           //!< Defines the digital state power
    DIO_PIN_STATE_MAX   //!< Defines the maximum digital state
}DIO_PinState_e;


typedef enum
{
    FCPU_HB,
    PORT1_1,
    PORT1_2,
    PORT1_3,
    UHF_SEL,
    PORT1_5,
    PORT1_6,
    PORT1_7,
    DIO_MAX_PIN_NUMBER
}DIO_Channel_e;

//!< @todo [G0]Add 2x more typedef enums e.g. DIO_Mode_t and DIO_Resistor_t
typedef enum
{

}DIO_Mode_e; 

typedef enum
{

}DIO_Resistor_e;

typedef struct 
{
    DIO_Channel_e channel;
    DIO_Resistor_e resistor;
    DIO_PinState_e data;
    DIO_Mode_e function;    
}DIO_Config_t;

//!< @todo add slew rate settings enum


#ifdef __cplusplus
extern "C"{
#endif

const DIO_Config_t* const DIO_getConfig(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif  //DIO_H_