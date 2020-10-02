#include "headers.h"
#include "echo.h"

void echo(char ** input)
{
    if(input[1]==NULL)
    {
        printf("\n");
        return ;
    }
    for(int i=1;input[i]!=NULL;i++)
    {
        printf("%s ",input[i]);
    }
}