/**
 * @file    dio.c
 * @author  Gabriel Ocaga (you@domain.com)
 * @brief   This implements the dio.
 * @version 1.x.x
 * @date    2025-05-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "dio.h"
#include <xxx.h>   //!< For Hardware Definitions

/**
 * @brief Defines a table of pointes to the peripheral input register on the 
 *        microcontroller. 
 * 
 */
static TYPE volatile* const dataIn[NUM_PORTS] =
{
    (TYPE*)&REGISTER1,
    (TYPE*)&REGISTER2,
};

static TYPE volatile* const dataDirection[NUM_PORTS] =
{
    (TYPE*)&REGISTER1,
    (TYPE*)&REGISTER2,
};

static TYPE volatile* const dataOut[NUM_PORTS] =
{
    (TYPE*)&REGISTER1,
    (TYPE*)&REGISTER2,
};

static TYPE volatile* const resistor[NUM_PORTS] =
{
    (TYPE*)&REGISTER1,
    (TYPE*)&REGISTER2,
};

static TYPE volatile* const function[NUM_PORTS] =
{
    (TYPE*)&REGISTER1,
    (TYPE*)&REGISTER2,
};

/**
 * @brief This funciton is used to initialise the DIO based on the configuration
 * table defined in dio_config module.
 * 
 * PRE-CONDITION: Configuration table needs to be populated with (sizeof > 0)
 * PRE-CONDITION: NUMBER_OF_CHANNELS_PER_PORY > 0
 * PRE-CONDITION: NUMBER_OF_PORTS > 0
 * PRE-CONDITION: The MCU clocks must be configured and enabled.
 * 
 * POST-CONDITION: The DIO peripheral is set up with the configuration settings.
 * 
 * @param config is a pointer to the configuration table that contains the 
 *               initialisation for the peripheral.
 * 
 * @return void
 * 
 * @example
 * @code
 * const DIO_Config_e* DIO_Config = DIO_getConfig();
 * 
 * DIO_init(DIO_Config);
 * @endcode
 * 
 * @see DIO_init
 * @see DIO_readChannel
 * @see DIO_writeChannel
 * @see DIO_toggleChannel
 * @see DIO_writeRegister
 */
void DIO_init(const DIO_Config_e* const config)
{
    //!< @todo [GO] Define Implementationi
    uint8_t index       = 0;
    uint8_t port_number = 0;
    uint8_t pin_number  = 0;

    for (index = 0; index < NUM_DIGITAL_PINS; index++)
    {
        port_number = config[index].channel / NUM_PINS_PER_PORT;
        pin_number  = config[index].channel % NUM_PINS_PER_PORT;

        //!< Set the Data-Direction register but for this channel
        if (config[index].direction == OUTPUT)
        {
            *portsaddr[port_number] |= (1UL << (pin_number));
        }
        else
        {
            *portsaddr[port_number] &= ~(1UL << (pin_number));
        }

        //!< Set the Data register bit for this channel
        if (config[index].data == HIGH)
        {
            *ports[port_number] |= (1UL << (pin_number));
        }
        else
        {
            *ports[port_number] &= ~(1UL << (pin_number));
        }
    }
}

/**
 * @brief This funciton is used to read the state of a DIO channel (pin) 
 * 
 * PRE-CONDITION: The chhannel is configured as INPUT.
 * PRE-CONDITION: The channel is configured as GPIO. 
 * PRE-CONDITION: The channle is within the maximum DIO_Channel_e definition.
 * 
 * POST-CONDITION: The channel state is returned.
 * 
 * @param channel is the DIO_Channel_e that represents a pin
 * 
 * @return The state of the channel as HIGH or LOW
 * 
 * @example
 * @code
 *  uint8_t pin = DIO_readChannel(PORT1_0);
 * 
 * DIO_init(DIO_Config);
 * @endcode
 * 
 * @see DIO_init
 * @see DIO_readChanniel
 * @see DIO_writeChannel
 * @see DIO_toggleChannel
 * @see DIO_writeRegister
 */
DIO_PinState_e DIO_readChannel(DIO_Channel_e channel)
{
    //!< Read the port associated with the desired pin
    DIO_PinState_e port_state = (DIO_PinState_e)*portsin[channel / NUM_PINS_PER_PORT];
}

/**
 * @brief 
 * 
 * @param channel 
 * @param state 
 */
void DIO_writeChannel(DIO_Channel_e channel, DIO_PinState_e state)
{

}

/**
 * @brief 
 * 
 * @param channel 
 */
void DIO_toggleChannel(DIO_Channel_e channel)
{

}

/**
 * @brief 
 * 
 * @param address 
 * @param value 
 */
void DIO_writeChannel(uint32_t address, TYPE value)
{

}

/**
 * @brief 
 * 
 * @param address 
 * @return TYPE 
 */
TYPE DIO_readRegister(uint32_t address)
{

}

/**
 * @brief 
 * 
 * @param function 
 * @param CallbackFunction 
 */
void DIO_callbackRegister(DIO_Callback_t function, TYPE (*CallbackFunction)(type))
{

}