#include "headers.h"
#include "indiv.h"
#include "exec.h"
#include"gopipe.h"
void indiv(char** args)
{
    for(int i=0 ; args[i]!=NULL ;i++)
    {
      int size = 0;
      char *pipeline[1000];
      char *tok = strtok(args[i],"|\n");
      while(tok!=NULL)
      {
          pipeline[size++] = tok;
          tok = strtok(NULL,"|\n");
      }
      gopipe(pipeline,size);
    }
}