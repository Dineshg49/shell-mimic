#include "headers.h"
#include "exec.h"
#include "initial.h"
#include "cd.h"
#include "pwd.h"
#include "echo.h"
#include "ls.h"
#include "pinfo.h"
#include "fg.h"
#include "bg.h"
#include"pipe.h"
#include "set.h"
#include"jobs.h"
#include"kjob.h"
#include"overkill.h"
#include"global_var.h"
void exec(char **input)
{
    int i=0;
    while(input[i]!=NULL)
        i++;
    i--;
    int flag=0;
    if(strcmp(input[i],"&")==0)
    {
        flag =1;
        input[i]  = NULL;
    }

    if(input[0]!=NULL)
    {
        if(strcmp(input[0],"quit")==0)
        {
            chill=0;
        }
        else if(strcmp(input[0],"cd")==0)
        {
            cd(input);
        }
        else if(strcmp(input[0],"pwd")==0)
        {
            pwd();
        }
        else if(strcmp(input[0],"echo")==0)
        {
            echo(input);
        }
        else if(strcmp(input[0],"ls")==0)
        {
            ls(input);
        }
        else if(strcmp(input[0],"pinfo")==0)
        {
            pinfo(input);
        }
        else if(strcmp(input[0], "setenv") == 0)
        {
			set(input);
		}
		else if(strcmp(input[0], "unsetenv") == 0 )
        {
			unset(input);
		}
        else if(strcmp(input[0], "jobs") == 0 )
        {
			list_jobs();
		}
        else if(strcmp(input[0], "kjob") == 0 )
        {
			kjob(atoi(input[1]), atoi(input[2]));
		}
        else if(strcmp(input[0], "overkill") == 0 )
        {
			overkill();
		}
        else if(strcmp(input[0], "fg") == 0 )
        {
			fg(atoi(input[1]));
		}
        else if(strcmp(input[0], "bg") == 0 )
        {
			bg(atoi(input[1]));
		}
        else
        {
            if(flag)
                bgh(input);
            else
                fgh(input);
        }
        
    }
}