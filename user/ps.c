#include "types.h"
#include "pstat.h"
#include "user.h"
#include "fs.h"

int main(int argc, char *argv[])
{
    struct pstat pstat;

    if (argc > 1)
    {
        printf(2, "Usage: ps\n");
        exit();
    }

    if (getpinfo(&pstat) < 0)
    {
        printf(2, "ps: fail to get processes info\n");
        exit();
    } 

    for (int i = 0; i < NPROC; i++) {
        printf(2, "pid: %d, inuse: %d, tickets: %d, strides: %d, pass: %d, ticks: %d\n", \
        pstat.pid[i], pstat.inuse[i], pstat.tickets[i], pstat.strides[i], pstat.pass[i], pstat.ticks[i] );
    }

    exit();
}
