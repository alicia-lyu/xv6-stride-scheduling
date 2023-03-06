#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "pstat.h"

void spin()
{
	int i = 0;
  int j = 0;
  int k = 0;
	for(i = 0; i < 50; ++i)
	{
		for(j = 0; j < 10000000; ++j)
		{
      k = j % 10;
      k = k + 1;
    }
	}
}

int
main(int argc, char *argv[]) {
  int pid_parent = getpid();
  printf(1, "PID parent: %d\n", pid_parent);
  settickets(40);
  if (fork() == 0) { // child process 1
    int pidA = getpid();
    printf(1, "PID A: %d\n", pidA);
    settickets(30);
    spin();
    exit();
  } else {
    if (fork() == 0) { // child process 2
      int pidB = getpid();
      printf(1, "PID B: %d\n", pidB);
      settickets(20);
      spin();
      exit();
    }
  }
  spin(); // main process
  
  wait();
  wait();
  exit();
}
