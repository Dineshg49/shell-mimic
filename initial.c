#include "initial.h"
#include "headers.h"
#include"handler.h"
#include"signals.h"
#include"global_var.h"
void initial()
{
	child = -1;
	dirflag=0;
	current_fg_pid=-1;
	strcpy(prev,"\0");
	mainshellpid = getpid();
	chill=1;
	jobcnt=0;
	getcwd(basedir,100);
	char* token  = strtok(basedir,"/");
	base=0;
	while(token!=NULL)
	{
		base++;
		token = strtok(NULL,"/");
	}
	getcwd(basedir,100);
	strcpy(current,basedir);
	signal(SIGINT, ctrlc);
	signal(SIGTSTP, ctrlz);
	signal(SIGCHLD, handler);
}