// A1Q2 - Write program which accept file name and mode from user and open that file in specific mode.

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int mode = 0;

    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        printf("Please enter file name as a command line arguments\n");
        printf("Read : read, Write : write, Read and Write : WR \n");
        return -1;
    }

    if(strcmp(argv[2],"read") == 0)
    {
        mode = O_RDONLY;
    }
    else if(strcmp(argv[2],"write") == 0)
    {
        mode = O_WRONLY;
    }
    else if(strcmp(argv[2],"WR") == 0)
    {
        mode = O_RDWR;
    }

    fd = open(argv[1], mode);

    if(fd == -1)
    {
        printf("Unable to access %s file in %s mode \n", argv[1], argv[2]);
    }
    else
    {
        printf("you can access %s file in %s mode \n", argv[1], argv[2]);
    }


    return 0;   
}