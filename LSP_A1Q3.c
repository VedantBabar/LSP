// A1Q3 - Write program which accept file name and on mode and that program check whether our process can access that file in accepted mode or not. 

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int mode = 0;

    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        printf("Please enter file name and mode as a command line arguments\n");
        printf("Read : read, Write : write, Execute : execute \n");
        return -1;
    }

    if(strcmp(argv[2],"read") == 0)
    {
        mode = R_OK;
    }
    else if(strcmp(argv[2],"write") == 0)
    {
        mode = W_OK;
    }
    else if(strcmp(argv[2],"execute") == 0)
    {
        mode = X_OK;
    }

    if(access(argv[1], mode) < 0)
    {
        printf("Unable to access %s file in %s mode \n", argv[1], argv[2]);
    }
    else
    {
         printf("you can access %s file in %s mode \n", argv[1], argv[2]);
    }


    return 0;   
}