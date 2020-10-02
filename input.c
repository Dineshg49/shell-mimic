#include "headers.h"
#include "input.h"
#include"global_var.h"
char* input()
{
    char *str; 
    size_t bufsize = 10000, characters;
    str = (char *)malloc(bufsize * sizeof(char));
    getline(&str,&bufsize,stdin);
    if(strcmp(str,"\0")==0)
    {
      printf("\n");
      chill=0;
    }
    return str;
}