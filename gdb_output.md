(gdb) **b sys_settickets**
Breakpoint 1 at 0x105e5c: file kernel/sysproc.c, line 96.
(gdb) c
Continuing.
=> 0x105e5c <sys_settickets+6>: sub    $0x8,%esp

Breakpoint 1, sys_settickets () at kernel/sysproc.c:96
96        if (argint(0, &ticket_num) < 0) {
(gdb) c
Continuing.
=> 0x105e5c <sys_settickets+6>: sub    $0x8,%esp

Breakpoint 1, sys_settickets () at kernel/sysproc.c:96
96        if (argint(0, &ticket_num) < 0) {
(gdb) c
Continuing.
=> 0x105e5c <sys_settickets+6>: sub    $0x8,%esp

Breakpoint 1, sys_settickets () at kernel/sysproc.c:96
96        if (argint(0, &ticket_num) < 0) {
(gdb) **b kernel/proc.c:328**
Breakpoint 2 at 0x10451e: file kernel/proc.c, line 328.
(gdb) c
Continuing.
=> 0x10451e <scheduler+348>:    movl   $0x0,%gs:0x4

Breakpoint 2, scheduler () at kernel/proc.c:328
328         proc = 0;
(gdb) p {p->pid,p->stride,p->pass,p->ticks}
$1 = **{12, 6, 6, 1}**
(gdb) c
Continuing.
=> 0x10451e <scheduler+348>:    movl   $0x0,%gs:0x4

Breakpoint 2, scheduler () at kernel/proc.c:328
328         proc = 0;
(gdb) p {p->pid,p->stride,p->pass,p->ticks}
$2 = **{11, 4, 10, 2}**
(gdb) c
Continuing.
=> 0x10451e <scheduler+348>:    movl   $0x0,%gs:0x4

Breakpoint 2, scheduler () at kernel/proc.c:328
328         proc = 0;
(gdb) p {p->pid,p->stride,p->pass,p->ticks}
$3 = **{12, 6, 12, 2}**
(gdb) c
Continuing.
=> 0x10451e <scheduler+348>:    movl   $0x0,%gs:0x4

Breakpoint 2, scheduler () at kernel/proc.c:328
328         proc = 0;
(gdb) p {p->pid,p->stride,p->pass,p->ticks}
$4 = **{11, 4, 14, 3}**
(gdb) c
Continuing.
=> 0x10451e <scheduler+348>:    movl   $0x0,%gs:0x4

Breakpoint 2, scheduler () at kernel/proc.c:328
328         proc = 0;
(gdb) p {p->pid,p->stride,p->pass,p->ticks}
$5 = **{12, 6, 18, 3}**
(gdb) c
Continuing.
=> 0x10451e <scheduler+348>:    movl   $0x0,%gs:0x4

Breakpoint 2, scheduler () at kernel/proc.c:328
328         proc = 0;
(gdb) p {p->pid,p->stride,p->pass,p->ticks}
$6 = **{11, 4, 18, 4}**
(gdb) c
Continuing.
=> 0x10451e <scheduler+348>:    movl   $0x0,%gs:0x4

Breakpoint 2, scheduler () at kernel/proc.c:328
328         proc = 0;
(gdb) p {p->pid,p->stride,p->pass,p->ticks}
$7 = **{11, 4, 22, 5}**
(gdb) c
Continuing.
=> 0x10451e <scheduler+348>:    movl   $0x0,%gs:0x4

Breakpoint 2, scheduler () at kernel/proc.c:328
328         proc = 0;
(gdb) p {p->pid,p->stride,p->pass,p->ticks}
$8 = **{12, 6, 24, 4}**
(gdb) c
Continuing.
=> 0x10451e <scheduler+348>:    movl   $0x0,%gs:0x4

Breakpoint 2, scheduler () at kernel/proc.c:328
328         proc = 0;
(gdb) p {p->pid,p->stride,p->pass,p->ticks}
$9 = **{11, 4, 26, 6}**
(gdb) c
Continuing.
=> 0x10451e <scheduler+348>:    movl   $0x0,%gs:0x4

Breakpoint 2, scheduler () at kernel/proc.c:328
328         proc = 0;
(gdb) p {p->pid,p->stride,p->pass,p->ticks}
$10 = **{12, 6, 30, 5}**
(gdb) c
Continuing.
=> 0x10451e <scheduler+348>:    movl   $0x0,%gs:0x4

Breakpoint 2, scheduler () at kernel/proc.c:328
328         proc = 0;
(gdb) p {p->pid,p->stride,p->pass,p->ticks}
$11 = **{11, 4, 30, 7}**
(gdb) c
Continuing.
=> 0x10451e <scheduler+348>:    movl   $0x0,%gs:0x4

Breakpoint 2, scheduler () at kernel/proc.c:328
328         proc = 0;
(gdb) p {p->pid,p->stride,p->pass,p->ticks}
$12 = **{11, 4, 34, 8}**
(gdb) c
Continuing.
=> 0x10451e <scheduler+348>:    movl   $0x0,%gs:0x4

Breakpoint 2, scheduler () at kernel/proc.c:328
328         proc = 0;
(gdb) p {p->pid,p->stride,p->pass,p->ticks}
$13 = **{12, 6, 36, 6}**
(gdb) c
Continuing.
=> 0x10451e <scheduler+348>:    movl   $0x0,%gs:0x4

Breakpoint 2, scheduler () at kernel/proc.c:328
328         proc = 0;
(gdb) p {p->pid,p->stride,p->pass,p->ticks}
$14 = **{11, 4, 38, 9}**
(gdb) c
Continuing.
=> 0x10451e <scheduler+348>:    movl   $0x0,%gs:0x4

Breakpoint 2, scheduler () at kernel/proc.c:328
328         proc = 0;
(gdb) p {p->pid,p->stride,p->pass,p->ticks}
$15 = **{12, 6, 42, 7}**
(gdb) c
Continuing.
=> 0x10451e <scheduler+348>:    movl   $0x0,%gs:0x4

Breakpoint 2, scheduler () at kernel/proc.c:328
328         proc = 0;
(gdb) p {p->pid,p->stride,p->pass,p->ticks}
$16 = **{11, 4, 42, 10}**
(gdb) 