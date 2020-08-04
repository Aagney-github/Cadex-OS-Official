/*
Copyright (C) 2019-2020 OpenCreeck
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/

/*
Splash screen for Cadex OS. In development.
*/

#include <library/syscalls.h>
#include <library/stdio.h>
#include <library/string.h>

typedef unsigned int uint32_t;

uint32_t randint(uint32_t min, uint32_t max);
void move(int *x, int *d, int min, int max);
char* message = "Cadex OS v0.1.3b2.0";
int main(int argc, char *argv[])
{
	int r = 255;
	int g = 0;
	int b = 0;
	int x1 = 12;
	int y1 = 12;
	int dx1 = 4;
	int dy1 = 1;
	int dr = -1;
	int dg = 2;
	int db = 3;

	int dims[2];
	syscall_object_size(WN_STDWINDOW, dims, 2);

	int width = dims[0];
	int height = dims[1];

	renderWindow(WN_STDWINDOW);
	clearScreen(0, 0, width, height);
	flush();
	move(&x1, &dx1, 0, width - 80);
	move(&y1, &dy1, 0, height - 1);
	char stop = -1;
	// while(stop == -1) {
	renderWindow(WN_STDWINDOW);
	move(&r, &dr, 0, 255);
	move(&g, &dg, 0, 255);
	move(&b, &db, 0, 255);
	setTextColor(r, g, b);
	print(x1, y1, message);
	flush();

	sleepThread(2);
	// syscall_object_read_nonblock(KNO_STDIN,&stop,1);
	// }
	
	// The code below is commented because its useless. It was written to make the typewriter animation but it failed.
	/* for (o = 0; o = 10; o++)*/
	/* {*/
	/* 	 renderWindow(WN_STDWINDOW);*/
	/* 	 setTextColor(255, 255, 255);*/
	/* 	 clearScreen(0, 0, width, height);*/
	/* 	 print(x1, y1, splashMessage[1]);*/
	/* 	 flush();*/
	/* 	 sleepThread(1000);*/
	/* }*/
	clearScreen(0, 0, width, height);
	setTextColor(255, 255, 255);
	flush();

	return 0;
}

uint32_t randint(uint32_t min, uint32_t max)
{
	static uint32_t state = 0xF3DC1A24;
	state = (state * 1299721) + 29443;
	return min + ((state >> 16) % (max - min + 1));
}

void move(int *x, int *d, int min, int max)
{
	*x += *d;
	if (*x < min)
	{
		*x = min;
		*d = randint(1, 10);
	}
	if (*x > max)
	{
		*x = max;
		*d = -randint(1, 10);
	}
}
