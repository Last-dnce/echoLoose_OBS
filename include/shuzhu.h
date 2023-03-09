#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdint.h>


#ifdef WIN_DLL
#define EXPORT __declspec(dllexport) /* for Windows DLL */
#else
#define EXPORT
#endif
#define MAXOBSTYPE  64                  /* max number of obs type in RINEX */
#define MAXRNXLEN   (16*MAXOBSTYPE+4)   /* max RINEX record length */

typedef __time_t time_t;

typedef struct {        /* time struct */
	time_t time;        /* time (s) expressed by standard time_t */
	double sec;         /* fraction of second under 1 s */
} gtime_t;

EXPORT int str2time(const char* s, int i, int n, gtime_t* t, int type);
EXPORT gtime_t epoch2time(const double* ep);
EXPORT void time2epoch(gtime_t t, double* ep);


