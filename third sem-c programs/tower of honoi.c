#include <stdio.h>
void towers(int,char,char,char);
void main()
{
    int num;
    printf("Enter number of disks::");
    scanf("%d",&num);
    printf("The sequence of movements involved in the tower of honoi are :\n");
    towers(num,'A','C','B');
}
void towers(int num,char frompeg,char toppeg,char auxpeg)
{
    if(num==1)
    {
        printf("\nMove disk 1 from peg %c to peg %c",frompeg,toppeg);
        return;
    }
    towers(num-1,frompeg,auxpeg,toppeg);
    printf("\nMove disk %d from peg %c to peg %c",num,frompeg,toppeg);
    towers(num-1,auxpeg,toppeg,frompeg);
}
