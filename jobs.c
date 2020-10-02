#include"headers.h"
#include "jobs.h"
#include"global_var.h"
void list_jobs()
{
    for(int i=0; i < jobcnt;i++)
    {
        char filepath[1000];
        char *str = "/proc/\0";
        strcpy(filepath,str);
        int pid = job[i].id;
        if(pid < 0)
            continue;
        int len=0;
        int cp = pid;
        while(cp > 0)
        {
            cp/=10;
            len++;
        }
        char pidc[1000];
        pidc[len] = '\0';
        int j=0;
        while(j<len)
        {
            pidc[len-j-1] = (char)(48 + (pid%10));
            pid/=10;
            j++;
        }
        strcat(filepath,pidc);
        char * onemorestring = "/stat\0";
        strcat(filepath,onemorestring);
        FILE * fd = fopen(filepath,"r");
        char c , arr[100][100];
        j=0;
        int k=0;
        while((c=getc(fd))!=EOF)
        {
            if(c == ' ' || c== '\n')
            {
                arr[j][k] = '\0';
                j++;
                k=0;
            }
            else
            {
                arr[j][k] = c;
                k++;
            }
        }
        char status[100];
        if(strcmp(arr[2],"T" )==0)
            strcpy(status, "Stopped");
        else
            strcpy(status, "Running");
        
        printf("[%d] %s %s [%d] \n" ,i+1,status,job[i].name,job[i].id);
    }
}
