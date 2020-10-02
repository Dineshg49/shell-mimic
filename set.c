#include"headers.h"
#include"set.h"

void set(char **command)
{
    if(command[3] != NULL)
    {
        perror("Too many arguments");
        return;
    }
    if(command[2][0] == '\0')
        setenv(command[1], " ", 1);
    else
        setenv(command[1], command[2], 1);
}

void unset(char **command)
{
    unsetenv(command[1]);
}
