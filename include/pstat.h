#ifndef _PSTAT_H_
#define _PSTAT_H_
#include "param.h"
struct pstat {
  int inuse[NPROC];   // whether this slot of the process table is in use (1 or 0)
  int tickets[NPROC]; // the number of tickets this process has
  int strides[NPROC]; // the stride of each process
  int pass[NPROC];
  int pid[NPROC];
  int ticks[NPROC];
};
#endif // _PSTAT_H_