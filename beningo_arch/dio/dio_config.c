/**
 * @file dio_config.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-05-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include "dio_config.h"

 const DIO_Config_t DIO_Config[] =
 {
    { PORT1_0, DISABLED, OUTPUT, HIGH, FCN_GPIO },
    { PORT1_1, DISABLED, OUTPUT, HIGH, FCN_GPIO },
    { PORT1_2, DISABLED, OUTPUT, HIGH, FCN_GPIO },
    { PORT1_3, DISABLED, OUTPUT, HIGH, FCN_GPIO },
    { PORT1_4, DISABLED, OUTPUT, HIGH, FCN_GPIO },
    //!< @todo [GO] add ports 6 and 7
 };

/**
 * @brief This function is used to initilaise the DIO based on the config table
 *        defined in dio_config module.
 * 
 *        PRE-CONDITION: Config table needs to populate(sizeof > 0)
 * 
 *        POST-CONDITION: A  constant pointer ot the first memeber of the config
 *                        table will be returned.  
 * 
 * 
 * @return const DIO_Config_t* const 
 *         A pointer to the configuration table.
 * 
 * @example
 * @code
 * const DIO_ConfigType* DIO_Config = DIO_getConfig();
 * 
 * DIO_init(DIO_Config);
 * @endcode
 * 
 * @see DIO_init
 * @see DIO_readChannel
 * @see DIO_writeChannel
 * @see DIO_toggleChannel
 * @see DIO_writeRegister
 * @see DIO_readRegister
 */
const DIO_Config_t* const DIO_getConfig(void)
{
    //!< The cast is performaed to ensure that the address of the first element
    //!< of configuration table is returned as a constant pointer and NOT a 
    //!< pointer that can be modified.
    return (const*) DIO_Config[0];
}