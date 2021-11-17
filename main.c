#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

int runChild();
int main() {
  int x;
  if (fork()){
    // parent
    // fork again
    if (fork()){
      int status;
      int childPID = wait(&status);
      int timeSlept = WEXITSTATUS(status);
      printf("Child PID: %d\tAsleep for %d seconds\n", childPID, timeSlept);
      printf("parent is done \n");
      exit(0);
    }else{
      // child again
      return runChild();
    }
  }else{
    // child
    return runChild();
  }


  return 0;
}

int runChild(){
  printf("child pid: %d\n", getpid());
  srand( time(NULL) );
  int hold = rand() % (5 + 1 - 2) + 2;
  sleep(hold);
  printf("Finished\n");
  return hold;
}
