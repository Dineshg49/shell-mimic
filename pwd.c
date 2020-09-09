#include "headers.h"
#include "pwd.h"

void pwd()
{
    char string[100];
    getcwd(string,100);
    printf("%s\n" ,string);
}