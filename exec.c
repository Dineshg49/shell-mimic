#include "headers.h"
#include "exec.h"
#include "initial.h"
#include "cd.h"
#include "pwd.h"
#include "echo.h"
#include "ls.h"
#include "sys.h"
#include "pinfo.h"


void exec(char **input, int flag )
{
    if(input[0]!=NULL)
    {
        if(strcmp(input[0],"cd")==0)
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
        else
        {
            sys(input,flag);
        }
        
    }
}