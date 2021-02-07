#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    struct node *prev;
    int ssn,salary;
    char name[20],dept[10],desi[20],phno[10];
    struct node *next;
}*NN=NULL,*first=NULL,*last=NULL,*cur=NULL;
void create()
{
    int ssn,salary;
    char name[20],dept[10],desi[20],phno[10];
    NN =(struct node *)malloc(sizeof(struct node));
    NN->prev = NULL;
    NN->next = NULL;
    printf("\n Enter ssn of the employee : ");
    scanf("%d",&ssn);
    printf("\n Enter salary of the employee : ");
    scanf("%d",&salary);
    printf("\n Enter name of employee : ");
    scanf("%s",name);
    printf("\n Enter department of employee : ");
    scanf("%s",dept);
    printf("\n Enter designation of employee : ");
    scanf("%s",desi);
    printf("\n Enter phone no. of employee : ");
    scanf("%s",phno);
    NN->ssn = ssn;
    NN->salary=salary;
    strcpy(NN->name,name);
    strcpy(NN->dept,dept);
    strcpy(NN->desi,desi);
    strcpy(NN->phno,phno);
}
void insertf()
{
    create();
    if(first == NULL)
    {
        first = NN;
        last=first;
    }
    else
    {
        NN -> next = first;
        first->prev=NN;
        first = NN;
    }
    printf("\nInsertion success");
}

void insertr()
{
    create();
    if(first == NULL)
    {
        first = NN;
        last=first;
    }
    else
    {
        cur = last;
        cur -> next = NN;
        NN -> prev = cur;
        last=NN;
    }
    printf("\nInsertion success");
}

void deletef()
{
    if(first == NULL)
    {
        printf("List is Empty!!! Deletion not possible!!!");
        return;
    }
    else if(first==last)
    {
        cur=first;
        first=last=NULL;
        free(cur);
    }
    else
    {
        cur=first;
        first=first->next;
        first->prev=NULL;
        free(cur);
    }
    printf("deletion success");
}
void deleter()
{
    if(first == NULL)
    {
        printf("List is Empty!!! Deletion not possible!!!");
        return;
    }
    else if(first==last)
    {
        cur=first;
        first=last=NULL;
        free(cur);
    }
    else
    {
        cur=last;
        last=cur->prev;
        last->next=NULL;
        free(cur);
    }
    printf("deletion success");
}
void display()
{
    cur=first;
    if(cur == NULL)
    {
        printf("List empty to display \n");
        return;
    }
    printf("\n Linked list elements from begining : \n");
    while (cur!= NULL)
    {
        printf("\n%d\t%d\t%s\t%s\t%s\t%s",cur->ssn,cur->salary,cur->name,cur->dept,cur->desi,cur->phno);
        cur = cur->next;
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n_______MENU______\n1.Insert Node from front\n2.Insert Node from rear\n3.Delete Node from front\n4.Delete Node from rear\n5.Display\n6.exit\n__________________\nEnter  your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insertf();
            break;
        case 2:
            insertr();
            break;
        case 3:
            deletef();
            break;
        case 4:
            deleter();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("\nInvalid choice!!!");
        }
    }
}
