#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 50
int stack[MAX];
char post[MAX];
int top=-1;
void pushstack(int tmp);
void calculator(char c);
void main()
{
    int i;
    printf("Enter postfix notation::");
    scanf("%s",post);
    for(i=0; i<strlen(post); i++)
    {
        if(post[i]>='0'&&post[i]<='9')
            pushstack(i);
        if(post[i]=='+'||post[i]=='-'||post[i]=='*'||post[i]=='/'||post[i]=='^')
            calculator(post[i]);
    }
    printf("result::%d",stack[top]);
}
void pushstack(int tmp)
{
    top++;
    stack[top]=(int)(post[tmp]-48);
}
void calculator(char c)
{
    int a,b,ans;
    a=stack[top];
    stack[top]='\0';
    top--;
    b=stack[top];
    stack[top]='\0';
    top--;
    switch(c)
    {
    case '+':
        ans=b+a;
        break;
    case '-':
        ans=b-a;
        break;
    case '*':
        ans=b*a;
        break;
    case '/':
        ans=b/a;
        break;
    case '^':
        ans=pow(b,a);
        break;
    default:
        ans=0;
        break;
    }
    top++;
    stack[top]=ans;
}
