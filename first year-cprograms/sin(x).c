#include <stdio.h>
#include<math.h>
#define pi 3.142
int main()
{
    float nume,denom,term,x,sum=0;
    int degree,i;
    printf("enter the angle in degree:");
    scanf("%d",&degree);
    x=degree*(pi/180);
    nume=x;
    denom=1;
    i=2;
    do
    {
        term=nume/denom;
        sum=sum+term;
        nume=-nume*x*x;
        denom=denom*i*(i+1);
        i+=2;
    }while(fabs(term)>=0.00001);
    printf("calculated value of sin(%d)=%f\n",degree,sum);
    printf("predefined value of sin(%d)=%f\n",degree,sin(x));
    return 0;
}
