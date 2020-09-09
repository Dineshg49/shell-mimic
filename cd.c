#include "headers.h"
#include "cd.h"
#include "initial.h"

void cd(char** dir)
{
	if(dir[1]==NULL || strcmp(dir[1],"~")==0)
	{
		chdir(basedir);
	}
	else
	{
		int a= chdir(dir[1]);
		//printf("%s %d",dir[1],a);
		if(a==-1)
		{
			perror("eroor");
		}
	}
}