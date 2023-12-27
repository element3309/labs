#include "plt_scheduler.h"
#include "drv/plt_uart.h"
#include <stdio.h>

uint8_t some_data[12] = "Hello world!";

plt_uart_t plt_uart = {
		3
};


void plt_scheduler(void)
{
	plt_uart_transmit(&plt_uart, some_data, sizeof(some_data));
}

