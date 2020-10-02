#include "prompt.h"
#include "headers.h"
#include "initial.h"
#include"global_var.h"
#define CYAN "\x1b[96m"
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
			//red();
			printf("%s <%s@%s: %s> ", CYAN,username ,hostname , curr);
				strcpy(current,curr);

		//	printf("current = %s prev = %s\n",current,prev);
		}
		else
		{
			//red();
			printf("%s <%s@%s: ~/" ,CYAN,username ,hostname);
			strcpy(current,"~/");
			int cnt = 0;
			getcwd(curr,100);
			char* token = strtok(curr,"/");
			while(token!=NULL)
			{
				cnt++;
				if(cnt>base)
				{
					printf("%s/",token);
					strcat(current,token);
					strcat(current,"/");
				}
				token = strtok(NULL,"/");
			}
			printf(">");
			//printf("current = %s prev = %s\n",current,prev);
		}
		reset(); 
}