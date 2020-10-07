/**
 * Copyright (C) 2019-2020 OpenCreeck
 * This software is distributed under the GNU General Public License
 * See the file LICENSE for details
*/

/**
 * Curses library for CadexOS
 *
 * NOTE: This isn't the official code from
 * the developers of curses library. This is
 * completely written from scratch for CadexOS
 * using the libraries provided with CadexOS
*/
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
	int x;
	int y;
} WINDOW;

void initscr();
WINDOW newwin(int height, int width, int x, int y);
