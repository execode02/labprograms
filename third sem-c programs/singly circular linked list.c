#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int expon;
    struct node *next;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    return x;
}
NODE attach(int coeff,int expon,NODE head)
{
    NODE NN,cur;
    NN=getnode();
    NN->coeff=coeff;
    NN->expon=expon;
    cur=head->next;
    while(cur->next!=head)
        cur=cur->next;
    cur->next=NN;
    NN->next=head;
    return head;
}
NODE readpoly(NODE head)
{
    int i=1,coeff,expon,ans;
    do
    {
        printf("Enter the %d term:\n",i++);
        printf("Coefficient=");
        scanf("%d",&coeff);
        printf("Exponent   =");
        scanf("%d",&expon);
        head=attach(coeff,expon,head);
        printf("Enter 999 to continue:");
        scanf("%d",&ans);
    }
    while(ans==999);
    return head;
}
NODE addpoly(NODE head1,NODE head2,NODE head3)
{
    NODE a,b;
    int coeff;
    a=head1->next;
    b=head2->next;
    while(a!=head1&&b!=head2)
    {
        if(a->expon==b->expon)
        {
            coeff=a->coeff+b->coeff;
            if(coeff!=0)
                head3=attach(coeff,a->expon,head3);
            a=a->next;
            b=b->next;
        }
        else if(a->expon>b->expon)
        {
            head3=attach(a->coeff,a->expon,head3);
            a=a->next;
        }
        else
        {
            head3=attach(b->coeff,b->expon,head3);
            b=b->next;
        }
    }
    while(a!=head1)
    {
        head3=attach(a->coeff,a->expon,head3);
        a=a->next;
    }
    while(b!=head2)
    {
        head3=attach(b->coeff,b->expon,head3);
        b=b->next;
    }
    return head3;
}
void display(NODE head)
{
    NODE NN;
    if(head->next==head)
    {
        printf("\nPolynomial doesn't exist!!!");
        return;
    }
    NN=head->next;
    while(NN!=head)
    {
        printf("%dx^%d",NN->coeff,NN->expon);
        NN=NN->next;
        if(NN!=head)
            printf(" + ");
    }
}
void main()
{
    NODE head1,head2,head3;
    head1=getnode();
    head2=getnode();
    head3=getnode();
    head1->next=head1;
    head2->next=head2;
    head3->next=head3;
    printf("Enter the first polynomial:\n");
    head1=readpoly(head1);
    printf("\nEnter the second polynomial:\n");
    head2=readpoly(head2);
    head3=addpoly(head1,head2,head3);
    printf("\nPolynomial 1:\t\t");
    display(head1);
    printf("\nPolynomial 2:\t\t");
    display(head2);
    printf("\nResultant Polynomial:\t");
    display(head3);
}
