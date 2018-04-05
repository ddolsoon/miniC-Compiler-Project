#ifndef _TIMER_H
#define _TIMER_H

#include <sys/time.h>

struct timeval lt;
static int first = 1;

void set_timer ();
void reset_timer ();
double lab_timer ();
double get_timer ();
 
#endif

