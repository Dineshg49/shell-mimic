#include "divide_arg.h"
#include "headers.h"

char **divide(char * input)
{
   // printf("bhaag bhaag aaya sher aaya sher \n");
    char* token;
    char ** args = malloc(50*sizeof(char*));
    token  = strtok(input,";");
   // printf("bhaag bhaag aaya sher aaya sher \n");
    int i=0;
    while(token!=NULL)
    {
        args[i] = token;
        i++;
        token  = strtok(NULL,";");
        //printf("bhaag bhaag aaya sher aaya sher \n");
    }
    args[i] = NULL;
   // printf("bhaag bhaag aaya sher aaya sher \n");
    return args;
}