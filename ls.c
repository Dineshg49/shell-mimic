#include "headers.h"
#include "ls.h"

void ls(char** input)
{
    int a=0,l=0,cnt=0;
    struct dirent *name;
    struct stat directory;
    char date[100];

    for(int i=1; input[i]!=NULL;i++)
    {
        if(strcmp(input[i],"-a")==0)
            a=1;
        else if(strcmp(input[i],"-l")==0)
            l=1;
        else if(strcmp(input[i],"-al")==0)
        {
            a=1;
            l=1;
        }
        else if(strcmp(input[i],"-la")==0)
        {
            a=1;
            l=1;
        }
        else
            cnt++;
    }
    if(cnt==0)
    {
        DIR *dir = opendir(".");
        while((name = readdir(dir))!=NULL)
        {
            stat(name->d_name, &directory);
            if(a==0 && l==0)
            {
                if(name->d_name[0] != '.')
                printf("%s\n", name->d_name);
            }
            else if(a==1 && l==0)
            {
                printf("%s\n", name->d_name);
            }
            else if(a==0 && l==1)
            {
                if(name->d_name[0]!='.')
                {
                    printf( (S_ISDIR(directory.st_mode)) ? "d" : "-");
                    printf( (directory.st_mode & S_IRUSR) ? "r" : "-");
                    printf( (directory.st_mode & S_IWUSR) ? "w" : "-");
                    printf( (directory.st_mode & S_IXUSR) ? "x" : "-");
                    printf( (directory.st_mode & S_IRGRP) ? "r" : "-");
                    printf( (directory.st_mode & S_IWGRP) ? "w" : "-");
                    printf( (directory.st_mode & S_IXGRP) ? "x" : "-");
                    printf( (directory.st_mode & S_IROTH) ? "r" : "-");
                    printf( (directory.st_mode & S_IWOTH) ? "w" : "-");
                    printf( (directory.st_mode & S_IXOTH) ? "x" : "-");
                    printf(" %d", (int)directory.st_nlink);
                    struct group  *gr = getgrgid(directory.st_gid);
                    printf(" %s", gr->gr_name);
                    struct passwd *pw = getpwuid(directory.st_uid);
                    printf(" %s", pw->pw_name);
                    printf(" %6d", (int)directory.st_size);
                    strftime(date, 100, "%h %d %H:%M", localtime(&(directory.st_ctime)));
                    printf(" %s ", date);
                    printf(" %s", name->d_name);
                    printf("\n");
                }
            }
            else
            {
                printf( (S_ISDIR(directory.st_mode)) ? "d" : "-");
                printf( (directory.st_mode & S_IRUSR) ? "r" : "-");
                printf( (directory.st_mode & S_IWUSR) ? "w" : "-");
                printf( (directory.st_mode & S_IXUSR) ? "x" : "-");
                printf( (directory.st_mode & S_IRGRP) ? "r" : "-");
                printf( (directory.st_mode & S_IWGRP) ? "w" : "-");
                printf( (directory.st_mode & S_IXGRP) ? "x" : "-");
                printf( (directory.st_mode & S_IROTH) ? "r" : "-");
                printf( (directory.st_mode & S_IWOTH) ? "w" : "-");
                printf( (directory.st_mode & S_IXOTH) ? "x" : "-");
                printf(" %d", (int)directory.st_nlink);
                struct group  *gr = getgrgid(directory.st_gid);
                printf(" %s", gr->gr_name);
                struct passwd *pw = getpwuid(directory.st_uid);
                printf(" %s", pw->pw_name);
                printf(" %6d", (int)directory.st_size);
                strftime(date, 100, "%h %d %H:%M", localtime(&(directory.st_ctime)));
                printf(" %s ", date);
                printf(" %s", name->d_name);
                printf("\n");
            }
            
        }
        //printf("\n");
    }
    else
    {
        //char d[100];
        for(int i=1;input[i]!=NULL;i++)
        {
            if(strcmp(input[i],"-l")!=0 && strcmp(input[i],"-a")!=0 && strcmp(input[i],"-la")!=0 && strcmp(input[i],"-al")!=0)
            {
                DIR *dir = opendir(input[i]);
                printf("%s\n",input[i]);
                while((name = readdir(dir))!=NULL)
                {
                //   printf("ninja");
                    stat(name->d_name, &directory);
                    if(a==0 && l==0)
                    {
                        if(name->d_name[0] != '.')
                        printf("%s\n", name->d_name);
                    }
                    else if(a==1 && l==0)
                    {
                        printf("%s\n", name->d_name);
                    }
                    else if(a==0 && l==1)
                    {
                        if(name->d_name[0]!='.')
                        {
                            printf( (S_ISDIR(directory.st_mode)) ? "d" : "-");
                            printf( (directory.st_mode & S_IRUSR) ? "r" : "-");
                            printf( (directory.st_mode & S_IWUSR) ? "w" : "-");
                            printf( (directory.st_mode & S_IXUSR) ? "x" : "-");
                            printf( (directory.st_mode & S_IRGRP) ? "r" : "-");
                            printf( (directory.st_mode & S_IWGRP) ? "w" : "-");
                            printf( (directory.st_mode & S_IXGRP) ? "x" : "-");
                            printf( (directory.st_mode & S_IROTH) ? "r" : "-");
                            printf( (directory.st_mode & S_IWOTH) ? "w" : "-");
                            printf( (directory.st_mode & S_IXOTH) ? "x" : "-");
                            printf(" %d", (int)directory.st_nlink);
                            struct group  *gr = getgrgid(directory.st_gid);
                            printf(" %s", gr->gr_name);
                            struct passwd *pw = getpwuid(directory.st_uid);
                            printf(" %s", pw->pw_name);
                            printf(" %6d", (int)directory.st_size);
                            strftime(date, 100, "%h %d %H:%M", localtime(&(directory.st_ctime)));
                            printf(" %s ", date);
                            printf(" %s", name->d_name);
                            printf("\n");
                        }
                    }
                    else
                    {
                        printf( (S_ISDIR(directory.st_mode)) ? "d" : "-");
                        printf( (directory.st_mode & S_IRUSR) ? "r" : "-");
                        printf( (directory.st_mode & S_IWUSR) ? "w" : "-");
                        printf( (directory.st_mode & S_IXUSR) ? "x" : "-");
                        printf( (directory.st_mode & S_IRGRP) ? "r" : "-");
                        printf( (directory.st_mode & S_IWGRP) ? "w" : "-");
                        printf( (directory.st_mode & S_IXGRP) ? "x" : "-");
                        printf( (directory.st_mode & S_IROTH) ? "r" : "-");
                        printf( (directory.st_mode & S_IWOTH) ? "w" : "-");
                        printf( (directory.st_mode & S_IXOTH) ? "x" : "-");
                        printf(" %d", (int)directory.st_nlink);
                        struct group  *gr = getgrgid(directory.st_gid);
                        printf(" %s", gr->gr_name);
                        struct passwd *pw = getpwuid(directory.st_uid);
                        printf(" %s", pw->pw_name);
                        printf(" %6d", (int)directory.st_size);
                        strftime(date, 100, "%h %d %H:%M", localtime(&(directory.st_ctime)));
                        printf(" %s ", date);
                        printf(" %s", name->d_name);
                        printf("\n");
                    }
                    
                }
            }
        }
    }
    
}