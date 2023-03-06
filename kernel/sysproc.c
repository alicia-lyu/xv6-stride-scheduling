#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "sysfunc.h"
#include "pstat.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;
  
  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since boot.
int
sys_uptime(void)
{
  uint xticks;
  
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_settickets(void) {
  int ticket_num;
  if (argint(0, &ticket_num) < 0) {
    proc->tickets = 1; // or return -1 ??
    proc->stride = MAX_STRIDE / proc->tickets + 1;
    return 0;
  }

  if (ticket_num < 1) {
    return -1;
  } else {
    proc->tickets = ticket_num;
    proc->stride = MAX_STRIDE / proc->tickets + 1; // in case tickets are too high that stride = 0
    return 0;
  }
}

int sys_getpinfo(void) {
  acquire(&ptable.lock);
  struct pstat* pstat;
  struct proc* p;
  if(argptr(0, (void*)&pstat, sizeof(*pstat)) < 0) {
    release(&ptable.lock);
    return -1;
  }
  if (pstat == 0) {
    release(&ptable.lock);
    return -1;
  }
  for(p = ptable.proc; p < &ptable.proc[NPROC]; p++) {
    int index = p - ptable.proc;
    if (p->state == UNUSED) {
      pstat->inuse[index] = 0;
    } else {
      pstat->inuse[index] = 1;
      pstat->pass[index] = p->pass;
      pstat->pid[index] = p->pid;
      pstat->tickets[index] = p->tickets;
      pstat->strides[index] = p->stride;
      pstat->pass[index] = p->pass;
      pstat->ticks[index] = p->ticks;
    }
  }
  release(&ptable.lock);
  return 0;
}
