#include "prompt.h"
#include "headers.h"
#include "initial.h"

void red () {
  printf("\033[1;31m");
}

void reset () {
  printf("\033[0m");
}

void prompt() {

    char hostname[100];
	char username[100];
	gethostname(hostname, 100);
	getlogin_r(username, 100);
	
		char curr[100];
		getcwd(curr,100);
		if(strstr(curr,basedir)==NULL)
		{
			getcwd(curr,100); 
			red();
			printf("<%s@%s: %s> " ,username ,hostname , curr);
		}
		else
		{
			red();
			printf("<%s@%s: ~/" ,username ,hostname);
			int cnt = 0;
			getcwd(curr,100);
			char* token = strtok(curr,"/");
			while(token!=NULL)
			{
				cnt++;
				if(cnt>base)
				{
					printf("%s/",token);
				}
				token = strtok(NULL,"/");
			}
			printf(">");
		}
		reset(); 
}