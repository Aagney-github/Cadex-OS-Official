/**
 * Copyright (C) 2019-2020 OpenCreeck
 * This software is distributed under the GNU General Public License
 * See the file LICENSE for details
*/

#pragma once

#include <library/_cheader.h>
#include <library/stdio.h>
#include <library/string.h>
#include <library/syscalls.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PI 3.1415926

extern double floor(double x);
extern int abs(int j);
extern double pow(double x, double y);
extern double exp(double x);
extern double fmod(double x, double y);
extern double sqrt(double x);
extern float sqrtf(float x);
extern double fabs(double x);
extern float fabsf(float x);
extern double sin(double x);
extern double cos(double x);

extern double frexp(double x, int* exp);

#define HUGE_VAL (__builtin_huge_val())

/* Unimplemented, but stubbed */
extern double acos(double x);
extern double asin(double x);
extern double atan2(double y, double x);
extern double ceil(double x);
extern double cosh(double x);
extern double ldexp(double a, int exp);
extern double log(double x);
extern double log10(double x);
extern double log2(double x);
extern double sinh(double x);
extern double tan(double x);
extern double tanh(double x);
extern double atan(double x);

extern double modf(double x, double* iptr);

extern double hypot(double x, double y);

#ifdef __cplusplus
}
#endif
