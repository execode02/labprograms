#include <stdio.h>
int main()
{
    int num,rev=0,rem,temp;
    printf("enter the number:");
    scanf("%d",&num);
    temp=num;
    while(temp!=0)
    {
        rem=temp%10;
        temp=temp/10;
        rev=rev*10+rem;
    }
    printf("reverse of the number %d=%d\n",num,rev);
    if(num==rev)
        printf("the entered number %d is a palindrome\n",num);
    else
        printf("the entered number %d is not a palindrome\n",num);
    return 0;
}
