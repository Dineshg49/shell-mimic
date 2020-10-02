#include"headers.h"
#include "delete.h"
#include "global_var.h"
void handler(int sig)
{
    pid_t pid;
    char *exit_status = (char *)calloc(1000, sizeof(char));
    char *exit = (char *)calloc(1000, sizeof(char));
    int stat;
    pid = waitpid(0, &stat, WNOHANG); //WNOHANG means parent does not wait if child does not terminate just check and return waitpid()
    sprintf(exit, "\nProcess with pid %d exited ", pid);
    if(WIFEXITED(stat)){
            delete_job(pid);
            sprintf(exit_status, "normally\n");
    }
    else if(WIFEXITED(stat) == 0){
            sprintf(exit_status, "abnormally\n");
    }
    else if(WIFSIGNALED(stat)){
        psignal(WTERMSIG(stat), "Exit signal");
    }
    if(pid > 0){
        write(2, exit, strlen(exit));
        write(2, exit_status, strlen(exit_status));
    }
    free(exit);
    return;
}

void signal_handler(int signum)
{
    if(jobcnt > 0)
        czz = 1;
    if(signum == SIGTSTP && foreground == 1 && czz == 1){
        if(command1 != '\0'){
            //printf("Pushing it in background");
            sleep(0);
            printf("\n");

        }
        else{
          //  printf("Hello\n");
            kill(job[jobcnt - 1].id, 9);
            delete_job(job[jobcnt - 1].id);
        }
    }
}
