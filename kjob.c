#include"headers.h"
#include"delete.h"
#include"global_var.h"
#include "kjob.h"
void kjob(int no, int signal)
{
    if(no > jobcnt)
        perror("Job");
    else
    {
        pid_t id = job[no-1].id;
        if(signal==9)
            delete_job(id);
        if(kill(id,signal) < 0)
            perror("error");
    }
}
