#include"headers.h"
#include"signal.h"
#include"delete.h"
#include"global_var.h"
#include "prompt.h"
void ctrlz(int signum)
{
	int pid = getpid();

	//printf("pid = %d mainshellpid = %d current_fg_pid = %d\n ",pid,mainshellpid,current_fg_pid);
	if(pid != mainshellpid)
		return;
	if(current_fg_pid != -1)
	{
		kill(current_fg_pid,SIGTTIN);
		kill(current_fg_pid,SIGTSTP);

		job[jobcnt].id = current_fg_pid;
		strcpy(job[jobcnt].name,current_fg);

		jobcnt++;
	}
	else
		fflush(stdout);

	signal(SIGTSTP, ctrlz);	
	printf("yah pe aaya h\n");		
}

void ctrlc(int signum)
{
    int pid = getpid();
	if(pid!=mainshellpid)
		return;
	if(current_fg_pid!=-1)
	{
		kill(current_fg_pid,SIGINT);
		signal(SIGINT,ctrlc);
	}
}

