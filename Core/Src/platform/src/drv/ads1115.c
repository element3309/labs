/*
 * ads1115.c
 *
 *  Created on: 2 дек. 2022 г.
 *      Author: PC02
 */
#include "ads1115.h"

/**
 * @brief chip register definition
 */
#define ADS1115_REG_CONVERT         0x00        /**< adc result register */
#define ADS1115_REG_CONFIG          0x01        /**< chip config register */
#define ADS1115_REG_LOWRESH         0x02        /**< interrupt low threshold register */
#define ADS1115_REG_HIGHRESH        0x03        /**< interrupt high threshold register */

/**
 * @brief iic address definition
 */
#define ADS1115_ADDRESS1        (0x48 << 1)        /**< iic address 1 */
#define ADS1115_ADDRESS2        (0x49 << 1)        /**< iic address 2 */
#define ADS1115_ADDRESS3        (0x4A << 1)        /**< iic address 3 */
#define ADS1115_ADDRESS4        (0x4B << 1)        /**< iic address 4 */

#define ADS1115_CHANNEL_BIT		14
#define ADS1115_MODE_BIT		8
#define	ADS1115_RATE_BIT 		7

void ads1115_write_config();
void ads115_write_reg(uint8_t reg, uint16_t value);
uint16_t ads115_read_reg(uint8_t reg);

ads1115_config_t config;
extern I2C_HandleTypeDef hi2c1;

uint16_t _reg = 0x8583; // 0b1000010110000011 default

void ads1115_write_config()
{
	ads115_write_reg(ADS1115_REG_CONFIG,_reg);
}

void ads115_write_reg(uint8_t reg, uint16_t value)
{
	uint8_t buffer[3] = {0};
	buffer[0] = reg;
	buffer[1] = value >> 8;
	buffer[2] = value & 0xFF;
	HAL_I2C_Master_Transmit(&hi2c1, ADS1115_ADDRESS1, buffer, 3, 100);
}

uint16_t ads115_read_reg(uint8_t reg)
{
	uint8_t buffer[2] = {0};
	buffer[0] = reg;
	HAL_I2C_Master_Transmit(&hi2c1, ADS1115_ADDRESS1, buffer, 1, 50);
	HAL_I2C_Master_Receive(&hi2c1, ADS1115_ADDRESS1, buffer, 2, 50);
	return ((buffer[0] << 8) | buffer[1]);
	/* 0b111111111 - buffer[0]
	 * 0b001000100 - buffer[1]
	 * 0b11111111100000000
	 *          0b001000100
	 * 0b111111111 001000100
	 *
	 * */

}

void ads1115_init()
{
	config.range	= ADS1115_RANGE_1P024V;
	config.rate		= ADS1115_RATE_128SPS;
	config.channel	= ADS1115_CHANNEL_AIN0_AIN1;
	config.mode		= ADS1115_MODE_SINGLE_SHOT;

	//_reg = ads1115_get_config_reg();
	ads1115_write_config();
	uint16_t mask = config.range<<9;
	_reg |= mask;
	ads1115_write_config();
}

void ads1115_set_channel(ads1115_channel_t channel)
{
	config.channel = channel;

}

uint16_t ads1115_get_last_result()
{
	return ads115_read_reg(ADS1115_REG_CONVERT);
}

uint16_t ads1115_get_config_reg()
{
	return ads115_read_reg(ADS1115_REG_CONFIG);
}

uint16_t ads1115_shot_read()
{
	ads115_write_reg(ADS1115_REG_CONFIG,_reg|=(1 << 15));
	HAL_Delay(300);
	return ads115_read_reg(ADS1115_REG_CONVERT);
}

