#include "headers.h"
#include "input.h"

char *input()
{
    int bytes_read;
    ssize_t size = 0;
    char *string;

    bytes_read = getline (&string, &size, stdin);
    if (bytes_read == -1)
    {
        puts ("ERROR!");
    }
    else
    {
        // puts(string);
        // printf("main ninja hattori\n");
        return string;
    }
    
}