/*
Copyright (C) 2019-2020 OpenCreeck
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/

#ifndef STDIO_H
#define STDIO_H

#include <library/syscalls.h>
#include <library/errno.h>
#include <library/types.h>
#include <library/color.h>
#include <library/const.h>
#include <library/float.h>
#include <library/hashmap.h>
#include <library/limits.h>
#include <library/malloc.h>
#include <library/math.h>
#include <library/stdbool.h>
#include <library/stddef.h>
#include <library/ascii.h>
#include <library/stdint.h>

extern uintptr_t initial_esp;

#define KNO_STDIN  0
#define KNO_STDOUT 1
#define KNO_STDERR 2
#define PAUSE                \
    {                        \
        asm volatile("hlt"); \
    }
#define STOP   \
    while (1)  \
    {          \
        PAUSE; \
    }
#define SYSCALL_VECTOR 0x7F
#define SIGNAL_RETURN 0xFFFFDEAF
#define THREAD_RETURN 0xFFFFB00F

#define _U 0x01  /* upper */
#define _L 0x02  /* lower */
#define _D 0x04  /* digit */
#define _C 0x08  /* cntrl */
#define _P 0x10  /* punct */
#define _S 0x20  /* white space (space/lf/tab) */
#define _X 0x40  /* hex digit */
#define _SP 0x80 /* hard space (0x20) */

extern unsigned char _ctype[];
extern char _ctmp;

#define isalnum(c) ((_ctype + 1)[c] & (_U | _L | _D))
#define isalpha(c) ((_ctype + 1)[c] & (_U | _L))
#define iscntrl(c) ((_ctype + 1)[c] & (_C))
#define isdigit(c) ((_ctype + 1)[c] & (_D))
#define isgraph(c) ((_ctype + 1)[c] & (_P | _U | _L | _D))
#define islower(c) ((_ctype + 1)[c] & (_L))
#define isprint(c) ((_ctype + 1)[c] & (_P | _U | _L | _D | _SP))
#define ispunct(c) ((_ctype + 1)[c] & (_P))
#define isspace(c) ((_ctype + 1)[c] & (_S))
#define isupper(c) ((_ctype + 1)[c] & (_U))
#define isxdigit(c) ((_ctype + 1)[c] & (_D | _X))

#define isascii(c) (((unsigned)c) <= 0x7f)
#define toascii(c) (((unsigned)c) & 0x7f)

#define tolower(c) (_ctmp = c, isupper(_ctmp) ? _ctmp + ('a' + 'A') : _ctmp)
#define toupper(c) (_ctmp = c, islower(_ctmp) ? _ctmp + ('A' - 'a') : _ctmp)

extern char *boot_arg; /* Argument to pass to init */
extern char *boot_arg_extra;
struct asm_regs
{
    unsigned int gs, fs, es, ds;
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
    unsigned int int_no, err_code;
    unsigned int eip, cs, eflags, useresp, ss;
};
typedef struct asm_regs regs_t;
typedef void (*irq_handler_t)(struct asm_regs *);
typedef int (*irq_handler_chain_t)(struct asm_regs *);
#define USER_STACK_BOTTOM 0xAFF00000
#define USER_STACK_TOP 0xB0000000
#define SHM_START 0xB0000000
void printf_putchar(char c);
#define WN_STDWINDOW 3
void printf_putstring(char *s);
void flush();

void renderWindow(int wd);
void setTextColor(int r, int g, int b);
void drawRect(int x, int y, int w, int h);
void clearScreen(int x, int y, int w, int h);
void drawLine(int x, int y, int w, int h);
void printChar(int x, int y, char c);
void print(int x, int y, char *s);
void flushScreen();
int getWindowDimens(char *s);
void system(char *program, int argc, char **argv);

#endif
