/*
 * This file is part of the flashrom project.
 *
 * Copyright (C) 2021, TUXEDO Computers GmbH
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#if defined(__i386__) || defined(__x86_64__)

#include "programmer.h"
#include "hwaccess_x86_io.h"

void probe_superio(void)
{
	probe_superio_winbond();
	/* ITE probe causes SMSC LPC47N217 to power off the serial UART.
	 * Always probe for SMSC first, and if a SMSC Super I/O is detected
	 * at a given I/O port, do _not_ probe that port with the ITE probe.
	 * This means SMSC probing must be done before ITE probing.
	 */
	//probe_superio_smsc();
	probe_superio_ite();
}

int superio_count = 0;
#define SUPERIO_MAX_COUNT 3

struct superio superios[SUPERIO_MAX_COUNT];

int register_superio(struct superio s)
{
	if (superio_count == SUPERIO_MAX_COUNT)
		return 1;
	superios[superio_count++] = s;
	return 0;
}

/* Generic Super I/O helper functions */
uint8_t sio_read(uint16_t port, uint8_t reg)
{
	OUTB(reg, port);
	return INB(port + 1);
}

void sio_write(uint16_t port, uint8_t reg, uint8_t data)
{
	OUTB(reg, port);
	OUTB(data, port + 1);
}

void sio_mask(uint16_t port, uint8_t reg, uint8_t data, uint8_t mask)
{
	uint8_t tmp;

	OUTB(reg, port);
	tmp = INB(port + 1) & ~mask;
	OUTB(tmp | (data & mask), port + 1);
}

void sio_switch_ldn(uint16_t port, uint8_t ldn)
{
	sio_write(port, 0x07, ldn);
}

uint16_t sio_get_iobase(uint16_t port, uint8_t io_bar_number)
{
	return (sio_read(port, 0x60 + io_bar_number * 2) << 8) |
		sio_read(port, 0x61 + io_bar_number * 2);
}

uint16_t sio_read_id(uint16_t port, uint8_t io_bar_number)
{
	return (sio_read(port, 0x20) << 8) | sio_read(port, 0x21);
}

bool sio_is_ldn_enabled(uint16_t port)
{
	return (sio_read(port, 0x30) & 1) ? true : false;
}

#endif
