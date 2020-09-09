#include "initial.h"
#include "headers.h"
#include "sys.h"

void initial()
{
	bg=0;
	getcwd(basedir,100);
	char* token  = strtok(basedir,"/");
	base=0;
	while(token!=NULL)
	{
		base++;
		token = strtok(NULL,"/");
	}
	getcwd(basedir,100);
    //return base;
}