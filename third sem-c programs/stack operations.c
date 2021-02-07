#include <stdio.h>
#include <stdlib.h>
int top=-1,ele,size,a[5],i;
void push()
{
    if(top==size-1)
        printf("Stack full!!!");
    else
    {
        printf("Input a number::");
        scanf("%d",&ele);
        a[++top]=ele;
    }
}
void pop()
{
    if(top==-1)
        printf("Stack empty!!!");
    else
        printf("Deleted element=%d",a[top--]);
}
void disp()
{
    if(top==-1)
        printf("Stack is empty!!!");
    else
    {
        for(i=0; i<=top; i++)
            printf("\n%d",a[i]);
    }
}
void pal()
{
    int flag=0;
    if(top==-1)
    {
        printf("Stack is empty!!!");
        return;
    }
    for(i=0; i<((top+1)/2); i++)
        if(a[i]!=a[top-i])
        {
            flag=1;
            break;
        }
    if(flag==1)
        printf("\nNot palindrome");
    else
        printf("\nPalindrome");
}
void main()
{
    int ch;
    printf("Enter the size of the stack::");
    scanf("%d",&size);
    while(1)
    {
        printf("\n____________MENU_____________\n1.push\n2.pop\n3.display\n4.palindrome\n5.exit\n_____________________________\nEnter your choice::");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            disp();
            break;
        case 4:
            pal();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid input!!!");
            break;
        }
    }
}
