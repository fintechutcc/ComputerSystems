#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h> 
#include <unistd.h>   

int main()
{
    // creating 4 process using 2 fork calls
    // 1 parent : 2 child : 1 grand-child
    pid_t id1 = fork();
    pid_t id2 = fork();
  
    // parent process
    if (id1 > 0 && id2 > 0) {
        wait(NULL);
        wait(NULL);
        printf("Parent Terminated\n");
    }
  
    // 1st child
    else if (id1 == 0 && id2 > 0) {
  
        // sleep the process for 2 seconds
        // to ensure 2nd child executes first
        sleep(2);
        wait(NULL);
        printf("1st child Terminated\n");
    }
  
    // second child
    else if (id1 > 0 && id2 == 0) {
        // sleep the process for 1 second
        sleep(1);
        printf("2nd Child Terminated\n");
    }
  
    // grand child
    else {
        printf("Grand Child Terminated\n");
    }
  
    return 0;
}