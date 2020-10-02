#include"headers.h"
#include "delete.h"
#include"global_var.h"
int delete_job(pid_t pid)
{
    int i=0;
    while(i<jobcnt)
    {
        if(job[i].id==pid)
        {
            strcpy(current_fg,job[i].name);
            break;
        }
        i++;
    }
    if(i==jobcnt)
        return 0;
    jobcnt--;
    while(i<jobcnt)
    {
        strcpy(job[i].name,job[i+1].name);
        job[i].id = job[i+1].id;
        i++;
    }
    return 1;
}
