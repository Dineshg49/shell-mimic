#include "headers.h"
#include "sys.h"

#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

char buffer[100];
void handler(int sig)
{
  pid_t pid;
  pid = wait(NULL);
  if(pid!=-1)
  //   sprintf(buffer,"proc/%d/cmdline/",pid);
  //  // printf("bol2\n");
  //   FILE *ptr;
  //  // printf("bol2\n");
  //  char* name = (char*)calloc(1024,sizeof(char));
  //   ptr = fopen(buffer,"r");
  //   size_t size;
  //   size = fread(name, sizeof(char), 1024, ptr);
  //   if(size>0){
  //       if('\n'==name[size-1])
  //           name[size-1]='\0';
  //   }
  //   fclose(ptr);
    printf("\nProcess with [%d] exitted normally.\n" ,pid);

  bg--;
}

void sys(char **args, int bkgrflag)
{
  int pid, wpid;
  int status;
  signal(SIGCHLD, handler);

  pid = fork();
  if (pid == 0) {
    setpgrp();
    if (execvp(args[0], args) == -1) {
      perror("viv");
    }
    exit(1);
  } else if (pid < 0) {
    // Error forking
    perror("viv");
  }
  // bgflag=1 implies '&' operator has been used so background process initiated.
  if (!bkgrflag) {
    // WUNTRACED: return if process has exited or process has stopped 
    waitpid(pid, &status, WUNTRACED);
  } else {
    bg++;
    printf("[%d] %d\n", bg, pid);
    // WNOHANG: return if no process has exited
    waitpid(pid, &status, WNOHANG);
  }
return ;
// return 1 implies signal to calling function that we should prompt for input again.
}