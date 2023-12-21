#ifndef SRC_PLATFORM_SRC_DRV_PLT_USART_H_
#define SRC_PLATFORM_SRC_DRV_PLT_USART_H_


/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef struct
{
	int port;
} plt_uart_t;
/**********************
 * GLOBAL PROTOTYPES
 **********************/
void plt_uart_transmit(plt_uart_t *uart, uint8_t* data, uint16_t size);
/**********************
 *      MACROS
 **********************/




#endif /* SRC_PLATFORM_SRC_DRV_PLT_USART_H_ */
