#include <stdio.h>
#include <stdlib.h>
int f=0,r=0,count=0,cq[20],ele,size,i,j;
void push()
{
    if(count==size)
        printf("CQ is full");
    else
    {
        printf("Enter the element to be pushed::");
        scanf("%d",&ele);
        r=(r+1)%size;
        cq[r]=ele;
        count++;
    }
}
void pop()
{
    if (count==0)
        printf("CQ is empty");
    else
    {
        f=(f+1)%size;
        printf("Deleted element is %d",cq[f]);
        count--;
    }
}
void display()
{

    if(count==0)
        printf("CQ is empty");
    else
    {
        j=f;
        for(i=0; i<count; i++)
        {
            j=(j+1)%size;
            printf("\n%d",cq[j]);
        }
        printf("\n");
    }
}
void main()
{
    int ch;
    printf("Enter the size of the CQ::");
    scanf("%d",&size);
    while(1)
    {
        printf("\n____________MENU_____________\n1.push\n2.pop\n3.display\n4.exit\n_____________________________\nEnter your choice::");
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
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid input!!!");
            break;
        }
    }
}
