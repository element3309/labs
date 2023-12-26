/*
 * ads1115.h
 *
 *  Created on: 2 дек. 2022 г.
 *      Author: PC02
 */

#ifndef SRC_DRV_ADS1115_H_
#define SRC_DRV_ADS1115_H_

#include "main.h"

/**
 * @brief ads1115 range enumeration definition
 */
typedef enum
{
    ADS1115_RANGE_6P144V = 0x00,        /**< 6.144V range */
    ADS1115_RANGE_4P096V = 0x01,        /**< 4.096V range */
    ADS1115_RANGE_2P048V = 0x02,        /**< 2.048V range */
    ADS1115_RANGE_1P024V = 0x03,        /**< 1.024V range */
    ADS1115_RANGE_0P512V = 0x04,        /**< 0.512V range */
    ADS1115_RANGE_0P256V = 0x05,        /**< 0.256V range */
} ads1115_range_t;

/**
 * @brief ads1115 channel enumeration definition
 */
typedef enum
{
    ADS1115_CHANNEL_AIN0_AIN1 = 0x00,        /**< AIN0 and AIN1 pins */
    ADS1115_CHANNEL_AIN0_AIN3 = 0x01,        /**< AIN0 and AIN3 pins */
    ADS1115_CHANNEL_AIN1_AIN3 = 0x02,        /**< AIN1 and AIN3 pins */
    ADS1115_CHANNEL_AIN2_AIN3 = 0x03,        /**< AIN2 and AIN3 pins */
    ADS1115_CHANNEL_AIN0_GND  = 0x04,        /**< AIN0 and GND pins */
    ADS1115_CHANNEL_AIN1_GND  = 0x05,        /**< AIN1 and GND pins */
    ADS1115_CHANNEL_AIN2_GND  = 0x06,        /**< AIN2 and GND pins */
    ADS1115_CHANNEL_AIN3_GND  = 0x07,        /**< AIN3 and GND pins */
} ads1115_channel_t;

/**
 * @brief ads1115 mode enumeration definition
 */
typedef enum
{
    ADS1115_MODE_CONTINUOUS  = 0x00,        /**< set mode continuous */
    ADS1115_MODE_SINGLE_SHOT = 0x01,        /**< set mode single shot */
} ads1115_mode_t;

/**
 * @brief ads1115 channel rate enumeration definition
 */
typedef enum
{
    ADS1115_RATE_8SPS   = 0x00,        /**< 8 sample per second */
    ADS1115_RATE_16SPS  = 0x01,        /**< 16 sample per second */
    ADS1115_RATE_32SPS  = 0x02,        /**< 32 sample per second */
    ADS1115_RATE_64SPS  = 0x03,        /**< 64 sample per second */
    ADS1115_RATE_128SPS = 0x04,        /**< 128 sample per second */
    ADS1115_RATE_250SPS = 0x05,        /**< 250 sample per second */
    ADS1115_RATE_475SPS = 0x06,        /**< 475 sample per second */
    ADS1115_RATE_860SPS = 0x07,        /**< 860 sample per second */
} ads1115_rate_t;

typedef struct
{
	ads1115_range_t		range;
	ads1115_channel_t	channel;
	ads1115_mode_t		mode;
	ads1115_rate_t		rate;
} ads1115_config_t;

void ads1115_init();
void ads1115_set_channel(ads1115_channel_t channel);
uint16_t ads1115_shot_read(void);
uint16_t ads1115_get_last_result(void);
uint16_t ads1115_get_config_reg(void);

#endif /* SRC_DRV_ADS1115_H_ */
