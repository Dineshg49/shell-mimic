#include "headers.h"
#include "indiv.h"
#include "exec.h"

void indiv(char** args)
{
    for(int i=0 ; args[i]!=NULL ;i++)
    {
        char* token;
        char** indargs = malloc(50*sizeof(char*));
        token  = strtok(args[i]," \t\r\n\a");
        int j=0;
        while(token!=NULL)
        {
            indargs[j] = token;
            j++;
            token = strtok(NULL , " \t\r\n\a");
        }
       // indargs[j] = NULL;
        if(j==0)
            continue;
        j--;
        int bg=0;
        if(indargs[j][strlen(indargs[j])-1]== '&')
        {
            bg=1;
            indargs[j]= NULL;
        }
        exec(indargs,bg);
    }
}