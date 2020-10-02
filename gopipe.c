#include "headers.h"
#include "indiv.h"
#include "exec.h"
#include "gopipe.h"
#include"redirection.h"
#include"pipe.h"
#include"global_var.h"
void gopipe(char** args, int size)
{
    for(int i = 0; i < size; i++)
    {
        int orgin = dup(STDIN_FILENO);
        int orgout =dup(STDOUT_FILENO);

        int num = 0;
        char *array[1000];
        char *tok = strtok(args[i]," \n\r\t"); 
        while(tok!=NULL)
        {
            array[num++] = tok;
            tok = strtok(NULL," \n\r\t");
        }

        redirection(array,num);

        if(size==1)
            exec(array);
        else
            fpipe(array,i,size);

        dup2(orgin,0);
        dup2(orgout,1);
        
        if(fd1>0)
            close(fd1);
        if(fd2>0)
            close(fd2);
        if(fd_open>0)
            close(fd_open);
        if(fd_write>0)
            close(fd_write);
    }
    
}