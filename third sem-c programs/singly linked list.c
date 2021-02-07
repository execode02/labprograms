#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=0;
struct node
{
    int sem;
    char name[20],branch[10],usn[10],phno[10];
    struct node *next;
}*first=NULL,*NN=NULL,*cur=NULL,*last=NULL;
void create()
{
    int sem;
    char name[20],branch[10],usn[10],phno[10];
    NN=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter usn,name, branch, sem, phno of student : \n");
    scanf("%s %s %s %d %s", usn, name,branch, &sem,phno);
    strcpy(NN->usn,usn);
    strcpy(NN->name,name);
    strcpy(NN->branch,branch);
    strcpy(NN->phno,phno);
    NN->sem = sem;
    NN->next=NULL;
    count++;
}
void insert_at_first()
{
    if (first == NULL)
    {
        create();
        first = NN;
        last=first;
    }
    else
    {
        create();
        NN->next = first;
        first = NN;
    }
}
void insert_at_last()
{
    if(first==NULL)
    {
        create();
        first = NN;
        last=first;
    }
    else
    {
        create();
        last->next=NN;
        last=NN;
    }
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
    printf("USN\tname\tbranch\tsem\tphno");
    while (cur!= NULL)
    {
        printf("\n%s\t%s\t%s\t%d\t%s",cur->usn,cur->name,cur->branch,cur->sem,cur->phno);
        cur = cur->next;
    }
    printf(" \nNo of students = %d ", count);
}

void deleteend()
{
    cur=first;
    if(first==NULL)
    {
        printf("List is empty!!!");
        return;
    }
    if(cur->next==NULL)
    {
        printf("\n%s %s %s %d %s", cur->usn, cur->name,cur->branch,cur->sem, cur->phno );
        free(cur);
        first=last=NULL;
    }
    else
    {
        while(cur->next!=last)
            cur=cur->next;
        printf("\n%s %s %s %d %s\n", last->usn, last->name,last->branch, last->sem, last->phno );
        free(last);
        cur->next=NULL;
        last=cur;
    }
    count--;
}
void deletefront()
{
    cur=first;
    if(first==NULL)
    {
        printf("List is empty!!!");
        return;
    }
    if(cur->next==NULL)
    {
        printf("\n%s %s %s %d %s", cur->usn, cur->name,cur->branch,cur->sem, cur->phno );
        free(cur);
        first=last=NULL;
    }
    else
    {
        first=cur->next;
        printf("\n%s %s %s %d %s", cur->usn, cur->name,cur->branch,cur->sem, cur->phno );
        free(cur);
    }
    count--;
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n-----------------MENU----------------------\n1.insert at first\n2.Insert at last\n3.delete at first\n4.delete at last\n5.display\n6.exit\n-------------------------------------------\n\nEnter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_at_first();
            break;
        case 2:
            insert_at_last();
            break;
        case 3:
            deletefront();
            break;
        case 4:
            deleteend();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("invalid choice\n");
            break;
        }
    }
}
