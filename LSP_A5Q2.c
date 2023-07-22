#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct Employee
{
    int E_ID;
    char Ename[20];
    float Expirience;
    int Age;
};

int main(int argc, char *argv[])
{
    struct Employee sobj;
    char Fname[20];
    int fd = 0;

    printf("Enter the file name : \n");
    scanf("%s",Fname);

    fd = open(Fname,O_RDONLY);

    read(fd,&sobj,sizeof(sobj));

    printf("Employee ID : %d : \n",sobj.E_ID);
    printf("Name : %s : \n",sobj.Ename);
    printf("Expirience : %f : \n",sobj.Expirience," years");
    printf("Age : %d : \n",sobj.Age);

    close(fd);

    return 0;
}