/*
Copyright (C) 2019-2020 OpenCreeck
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/

#ifndef MOUSE_H
#define MOUSE_H

#include "console.h"
#include "page.h"
#include "process.h"
#include "interrupt.h"
#include "keyboard.h"
#include "mouse.h"
#include "clock.h"
#include "ata.h"
#include "device.h"
#include "cdromfs.h"
#include "string.h"
#include "graphics.h"
#include "kernel/ascii.h"
#include "kernel/syscall.h"
#include "rtc.h"
#include "kernelcore.h"
#include "kmalloc.h"
#include "memorylayout.h"
#include "kshell.h"
#include "cdromfs.h"
#include "diskfs.h"
#include "serial.h"
#include <sysinfo.h>
#include "printf.h"
#include "service.h"

struct mouse_event
{
	int32_t x;
	int32_t y;
	uint8_t buttons;
};
uint8_t cycle;
uint8_t buttons;
int8_t buffer[3];

void mouse_read(struct mouse_event *e);
void mouse_init();
void mouse_interrupt(int i, int code);
#endif