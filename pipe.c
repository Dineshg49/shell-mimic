#include "pipe.h"
#include "headers.h"
#include "exec.h"
#include"indiv.h"
#include"global_var.h"
void fpipe(char **word,int i,int size)
{
    printf("%s %d %d\n" ,word[i], i , size);
    int val = size-1;
    int ret;
    if(i&1)
    {
        ret = pipe(mypipe1);
        if(ret < 0)
            perror("pipe");
    }
    else 
    {
        ret = pipe(mypipe2);
        if(ret < 0)
            perror("pipe");
    }
    int pid = fork();

    if(pid == -1)
        perror("Child process could not be created\n");
    else if(pid == 0)
    {
        if(i == 0)
            dup2(mypipe2[1],1);
        else if(i == size-1)
        {
            if(val&1) 
                dup2(mypipe2[0],0);
            else  
                dup2(mypipe1[0],0);               
        }
        else
        {
            if(i&1)
            {
                dup2(mypipe2[0],0);
                dup2(mypipe1[1],1);
            }   
            else 
            {
                dup2(mypipe1[0],0);
                dup2(mypipe2[1],1);
            }
        }
        exec(word);
        exit(0);
    }
    wait(NULL);
    if(i == 0)
    {
        close(mypipe2[1]);
    }
    else if(i == val)
    {
        if(val&1) 
             close(mypipe2[0]);
        else 
            close(mypipe1[0]);
    }
    else 
    {
        if(i&1)
        {
            close(mypipe2[0]);
            close(mypipe1[1]);
        }   
        else
        {
            close(mypipe1[0]);
            close(mypipe2[1]);
        }
    }
}