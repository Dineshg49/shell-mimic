#include "headers.h"
#include "echo.h"

void echo(char ** input)
{
    for(int i=1;input[i]!=NULL;i++)
    {
        printf("%s ",input[i]);
    }
}