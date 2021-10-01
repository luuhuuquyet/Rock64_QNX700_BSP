/*
* $QNXLicenseC:
* Copyright 2017, QNX Software Systems.
*
* You must obtain a written license from and pay applicable license fees to QNX
* Software Systems before you may reproduce, modify or distribute this software,
* or any work that includes all or part of this software. Free development
* licenses are available for evaluation and non-commercial purposes. For more
* information visit http://licensing.qnx.com or email licensing@qnx.com.
*
* This file may contain contributions from others. Please review this entire
* file for other proprietary rights or license notices, as well as the QNX
* Development Suite License Guide at http://licensing.qnx.com/license-guide/
* for other information.
* $
*/

#include "startup.h"
#include <aarch64/rk3328.h>

static void
parse_line(unsigned channel, const char *line, unsigned *baud, unsigned *clk, unsigned long *div)
{
	/*
	 * Get device base address and register stride
	 */
	if (*line != '.' && *line != '\0') {
		dbg_device[channel].base = strtopaddr(line, (char **)&line, 16);
		if (*line == '^')
			dbg_device[channel].shift = strtoul(line+1, (char **)&line, 0);
	}

	/*
	 * Get baud rate
	 */
	if (*line == '.')
		++line;
	if (*line != '.' && *line != '\0')
		*baud = strtoul(line, (char **)&line, 0);

	/*
	 * Get clock rate
	 */
	if (*line == '.')
		++line;
	if (*line != '.' && *line != '\0')
		*clk = strtoul(line, (char **)&line, 0);

	/*
	 * Get div
	 */
	if(*line == '.') 
		++line;
    if(*line != '.' && *line != '\0') 
    	*div = strtoul(line, (char **)&line, 0);
}

void
init_serns16550(unsigned channel, const char *init, const char *defaults)
{
	unsigned long 	baud;
	unsigned long	div;
	unsigned long	clk;
	paddr_t		base;
	unsigned int dll = 0;

	baud = 0;
	parse_line(channel, defaults, &baud, &clk, &div);
	parse_line(channel, init, &baud, &clk, &div);
	base = dbg_device[0].base;

	while (!(in32(base + RK3328_UART_LSR) & RK3328_UART_LSR_TEMT ));

	out32 (base + RK3328_UART_IER, 0);

	if (in32 (base + RK3328_UART_LSR) & RK3328_UART_LSR_DR){
		in32(base + RK3328_UART_RBR);
	}
	switch (baud) {
		case 1500000:
			dll = 0x1;
			break;
		case 115200:
		default:
			dll = 0xd;
			break;
	}	
	out32(base + RK3328_UART_IER, 0);
	out32(base + RK3328_UART_MCR, RK3328_UART_MCRVAL);
	out32(base + RK3328_UART_FCR, RK3328_UART_FCR_DEFVAL);

	out32(base + RK3328_UART_LCR, RK3328_UART_LCR_BKSE | RK3328_UART_LCRVAL);
	out32(base + RK3328_UART_DLL, dll & 0xff);
	out32(base + RK3328_UART_DLH, (dll >> 8) & 0xff);
	out32(base + RK3328_UART_LCR, RK3328_UART_MCRVAL);

}


/*
 * Send a character
 */
void
put_serns16550(int c)
{
	paddr_t base = dbg_device[0].base;

	while (!(in32(base + RK3328_UART_LSR) & RK3328_UART_LSR_THRE));

	out32(base + RK3328_UART_THR, c & 0xff);
}
