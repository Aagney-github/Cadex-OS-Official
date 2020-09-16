/**
 * Copyright (C) 2019-2020 OpenCreeck
 * This software is distributed under the GNU General Public License
 * See the file LICENSE for details
*/
/**
 * An application to clear the screen
*/
#include <library/stdio.h>
#include <library/color.h>

int main(int argc, char *argv[])
{
    int x1 = 12;
    int y1 = 12;
    int dims[2];
    char stop = -1;
    int i = 0;
    syscall_object_size(WN_STDWINDOW, dims, 2);

    int width = dims[0];
    int height = dims[1];

    renderWindow(WN_STDWINDOW);
    clearScreen(0, 0, width, height);
    flushScreen();
    flush();
    return 0;
}