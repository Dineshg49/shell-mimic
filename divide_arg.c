#include "divide_arg.h"
#include "headers.h"

char **divide(char * input)
{
    char* token;
    char ** args = malloc(100*sizeof(char*));
    if(!args)
    {
        fprintf(stderr, " Memory Allocation error\n");
        exit(EXIT_FAILURE);
    }
    token  = strtok(input,";");
    int i=0;
    while(token!=NULL)
    {
        args[i++] = token;
        token  = strtok(NULL,";");
    }
    args[i] = NULL;
    return args;
}