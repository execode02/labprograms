#include <stdio.h>
#include<stdlib.h>
int main()
{
    int i;
    float num,sqrt;
    printf("enter the number:");
    scanf("%f",&num);
    if(num>0)
    {
        sqrt=num/2;
        for(i=0;i<(int)num;i++)
            sqrt=(sqrt+num/sqrt)/2;
        printf("square root of %f=%f\n",num,sqrt);
    }
    else
        printf("square root is not possible for negative numbers\n");
}
