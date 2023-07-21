// A2Q5 - Write a program which accept directory name from user and print all file name of such a file having largest size.

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
    int iMax = 0;
    DIR * DP = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;
    char fname[300] = {'\0'};
    char LFname[20] = {'\0'};

    if(argc != 2)
    {
        printf("Insufficients arguments\n");
        return -1;
    }

    DP = opendir(argv[1]);

    if(DP == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    
    while((entry = readdir(DP)) != NULL)
    {
        sprintf(fname,"%s/%s",argv[1],entry->d_name);

        stat(fname,&sobj);

        if(sobj.st_size > iMax)
        {
            iMax = sobj.st_size;
            strcpy(LFname,entry->d_name);
        }

    }

    printf("%s have largest size : %d\n",LFname,iMax);

    closedir(DP);
    return 0;
}
