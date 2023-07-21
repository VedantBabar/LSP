// A1Q1 - Write program which accept file from user and open

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;

    if(argc != 2)
    {
        printf("Invalid number of Arguments \n");
        printf("Please enter file name as a command line arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open the file.\n");
    }
    else
    {
        printf("File open successfuly with FD : %d\n",fd);
    }

    return 0;
}