#include "headers.h"
#include "indiv.h"
#include "exec.h"
#include "gopipe.h"
#include "redirection.h"
#include"global_var.h"
void redirection(char** array,int length_arg)
{
    int stdin=0,stdout=0,stdout_append=0;
    int inputpos,outputpos,outputpos2;
    for(int check = 0; check<length_arg;check++)
    {
        if(strcmp(array[check],"<")==0)
        {
            stdin=1;
            inputpos = check;
        }
        if(strcmp(array[check],">")==0)
        {
            stdout=1;
            outputpos = check;
        }
        if(strcmp(array[check],">>")==0)
        {
            stdout_append=1;
            outputpos2 = check;
        }
    }
    fd1=0,fd2=0,fd_open=0,fd_write=0;
    if( stdin & !stdout & !stdout_append)
    {
        fd1 = open(array[inputpos+1],O_RDONLY,S_IRWXU);
        if(fd1 < 0)
            perror("open");
        dup2(fd1,0);
        length_arg = inputpos;
    }
    else if(!stdin & stdout  &  !stdout_append)
    {
        fd2 = open(array[outputpos+1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if(fd2 < 0)
            perror("open");
        dup2(fd2,1);
        length_arg = outputpos;
    }
    else if(!stdin & !stdout  && stdout_append)
    {
        fd2 = open(array[outputpos2+1],O_WRONLY | O_CREAT | O_APPEND,0644);
        if(fd2 < 0)
        {
            perror("open");
        }
        dup2(fd2,1);
        length_arg = outputpos2;
    }
    else if(stdin & stdout & !stdout_append)
    {
        fd_open,fd_write;
        fd_open = open(array[inputpos+1],O_RDONLY);
        if(fd_open < 0)
        {
            perror("open");
        }
        fd_write = open(array[outputpos+1], O_WRONLY | O_CREAT | O_TRUNC,0644);
        length_arg = inputpos;
    }
    else if(stdin & !stdout & stdout_append)
    {
        fd_open,fd_write;
        fd_open = open(array[inputpos+1],O_RDONLY);
        if(fd_open < 0)
        {
            perror("open");
        }
        fd_write = open(array[outputpos2+1], O_WRONLY|O_CREAT | O_APPEND,0644);
        dup2(fd_open,0);
        dup2(fd_write,1);
        length_arg = inputpos;
    }
    array[length_arg] = NULL;
}