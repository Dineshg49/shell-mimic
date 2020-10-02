#include"headers.h"
#include"delete.h"
#include"overkill.h"
#include"global_var.h"
void overkill()
{
    while(jobcnt)
    {
        int id  = job[0].id;
        delete_job(id);
        if(kill(id,9) < 0)
            perror("error");
    }
}
