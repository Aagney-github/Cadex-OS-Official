/*
Copyright (C) 2019-2020 OpenCreeck
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/

/* An application to make graphical dialogs */
#include <library/stdio.h>
#include <library/color.h>
#include <library/types.h>

int main(int argc, char const *argv[])
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

    // Check if length of command-line arguments is lesser than 0
    if(argc <= 0){
    //     // If length of command-line arguments is lesser than 0
       printf("usage: sdlg [options]... (title|bgcolor|fgcolor|button)\n");
       exit(0);
    }
    renderWindow(WN_STDWINDOW);
    clearScreen(0, 0, width, height);
    flush();
    setTextColor(GRAY, 0);
    drawRect(x1, y1, 190, 80);
    setTextColor(WHITE, 0);
    print(x1 + 10, y1 + 10, "Example dialog message");
    setTextColor(BLUE, 0);
    drawRect(x1 + 60, y1 + 50, 60, 20);
    setTextColor(WHITE, 0);
    print(x1 + 62, y1 + 52 + 3, "OK");
    resetColor();
    flush();
    return 0;
}
