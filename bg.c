#include"headers.h"
#include "handler.h"
#include"global_var.h"
void bgh(char **a)
{
     jobcnt++;
     pid_t pid;
     pid = fork(); 
     setpgid(0, 0);
     strcpy(job[jobcnt-1].name, a[0]);
     job[jobcnt-1].id = pid;
     if(pid < 0)
     {
         perror("Error"); 
         return;
     }
     current_bg_pid = pid;
     if(pid == 0)
     {
     	if (signal(SIGTSTP, signal_handler));
 
         if(execvp(a[0], a) == -1){
             perror("Error");
         }
         exit(0);
     }
 }

void bg(int no)
{
    if(no > jobcnt)
        printf("Enter valid job number");
    else 
        kill(job[no - 1].id, SIGCONT);
}
