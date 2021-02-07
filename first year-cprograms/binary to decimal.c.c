#include <stdio.h>
int convert(int bin);
int main()
{
    int bin,dec;
    printf("enter a binary number:");
    scanf("%d",&bin);
    dec=convert(bin);
    printf("decimal equivalent of %d=%d",bin,dec);
    return 0;
}
int convert(int bin)
{
    if(bin==0)
        return 0;
    else
        return (bin%10+2*convert(bin/10));
}
