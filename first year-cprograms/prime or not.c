#include <stdio.h>
int isprime(int num)
{
    int i;
    if(num==0||num==1)
        return 0;
    for(i=2;i<num;i++)
    {
        if(num%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int num,result;
    printf("enter a number: ");
    scanf("%d",&num);
    result=isprime(num);
    if(result==1)
        printf("the number %d is prime\n",num);
    else
        printf("the number %d is not prime\n",num);
    return 0;
}
