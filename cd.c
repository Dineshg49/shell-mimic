#include "headers.h"
#include "cd.h"
#include "initial.h"
#include "global_var.h"
void cd(char** dir)
{
	if(dir[1]==NULL || strcmp(dir[1],"~")==0)
	{
		strcpy(prev,current);
		chdir(basedir);
	}
	else if(strcmp(dir[1],"-")==0)
	{
		if(strcmp(prev,"\0")==0)
		{
			printf("No previous directory\n");
		}
		else
		{
			if(strcmp(prev,"~/")==0){
				chdir(basedir);
				printf("%s \n",basedir);
			}
			else{
				chdir(prev);
				printf("%s \n",prev);
			}
			strcpy(prev,current);
		}		
	}
	else
	{
		int a= chdir(dir[1]);
		strcpy(prev,current);
		if(a==-1)
		{
			perror("File");
		}
	}
}