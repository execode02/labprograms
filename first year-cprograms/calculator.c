#include<stdio.h>
int main()
{
    int num1,num2;
    float result;
    char op;
    printf("enter the arithmetic expression(operand1 operator operand2):\n");
    scanf("%d%c%d",&num1,&op,&num2);
    switch(op)
    {
        case '+':result=num1+num2;
                break;
        case '-':result=num1-num2;
                break;
        case '*':result=num1*num2;
                break;
        case '/':result=(float)num1/num2;
                break;
        case '%':result=num1%num2;
                break;
        default:printf("invalid operator\n");
                goto label;
                break;
    }
        printf("result:%d%c%d=%f\n",num1,op,num2,result);
        label:
    return 0;
}
