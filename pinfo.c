#include "headers.h"
#include "pinfo.h"
#include "initial.h"

void pinfo(char** input)
{
    if(input[1]==NULL)
    {
        char path[] = "/proc/self/stat";
        FILE* file = fopen(path,"r");
        char status[3];
        int faltu;
        char faltu2[1000];
        char mem[1000];
        fscanf(file, "%d" "%s" "%s" ,&faltu,faltu2 ,status);
        int i=0;
        while(i<20)
        {
            fscanf(file,"%s",mem);
            i++;
        }
        fclose(file);

        char buf[1000];
        readlink("/proc/self/exe", buf, sizeof(buf));

        printf("pid-- %d\n", getpid());
        printf("Process Status -- %s\n",status);
        printf("memory -- %s\n",mem);
        if(strstr(buf,basedir)==NULL)
        {
            printf("Executable path -- %s\n", buf);
        }
        else
        {
            printf("Executable Path --  ");
            int cnt=0;
            char* token = strtok(buf,"/");
			while(token!=NULL)
			{
                if(cnt==0)
                     printf("~");
				cnt++;
				if(cnt>base)
				{
                    
					printf("/%s",token);
				}
				token = strtok(NULL,"/");
			}
            printf("\n");
        }
    }
    else
    {
        char path[] = "/proc/";
        strcat(path,input[1]);
        strcat(path,"/stat");
        FILE* file = fopen(path,"r");
        char status[3];
        int faltu;
        char faltu2[1000];
        char mem[1000];
        fscanf(file, "%d" "%s" "%s" ,&faltu,faltu2 ,status);
        int i=0;
        while(i<20)
        {
            fscanf(file,"%s",mem);
            i++;
        }
        fclose(file);

        char buf[1000];
        char path2[] = "/proc/";
        strcat(path2,input[1]);
        strcat(path2,"/exe");
        readlink(path2, buf, sizeof(buf));

        printf("pid-- %s\n", input[1]);
        printf("Process Status -- %s\n",status);
        printf("memory -- %s\n",mem);
        if(strstr(buf,basedir)==NULL)
        {
            printf("Executable path -- %s\n", buf);
        }
        else
        {
            printf("Executable Path --  ");
            int cnt=0;
            char* token = strtok(buf,"/");
			while(token!=NULL)
			{
                if(cnt==0)
                     printf("~");
				cnt++;
				if(cnt>base)
				{
                    
					printf("/%s",token);
				}
				token = strtok(NULL,"/");
			}
            printf("\n");
        }
    }
    
}