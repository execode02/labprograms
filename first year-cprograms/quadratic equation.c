#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,root1,root2,real,img,det;
    printf("enter the coefficients of quadratic equation:");
    scanf("%f%f%f",&a,&b,&c);
    det=b*b-4*a*c;
    if(a==0&&b==0)
        printf("invalid input\n");
    else if(a==0)
    {
        printf("linear equation\n");
        root1=-c/a;
        printf("root=%f",root1);
    }
    else if(det==0)
    {
        printf("roots are real and equal\n");
        root1=-b/2*a;
        root2=-b/2*a;
        printf("root1=%f\nroot2=%f\n");
    }
    else if(det>0)
    {
        printf("roots are real and distinct\n");
        root1=(-b+sqrt(fabs(det)))/(2*a);
        root2=(-b-sqrt(fabs(det)))/(2*a);
        printf("root1=%f\nroot2=%f\n",root1,root2);
    }
    else
    {
        printf("roots are real and imaginary\n");
        real=-b/(2*a);
        img=(sqrt(fabs(det)))/(2*a);
        printf("real=%f\nimaginary=%f\n",real,img);
    }
    return 0;
}
