#include <stdio.h>
#include <stdlib.h>
int key[20],n,m;
int *ht,ind;
int count=0;
void insert(int key)
{
    ind=key%m;
    while(ht[ind]!=-1)
        ind=(ind+1)%m;
    ht[ind]=key;
    count++;
}
void display()
{
    int i;
    if(count==0)
    {
        printf("Hash table is empty!!!");
        return;
    }
    printf("Hash table contents are:\n");
    for(i=0;i<m;i++)
        printf("\nT[%d]-->%d",i,ht[i]);
}
void main()
{
    int i;
    printf("Enter number of employee records(N):");
    scanf("%d",&n);
    printf("Enter the two digit memory location(M) for hash table:");
    scanf("%d",&m);
    ht=(int *)malloc(m*sizeof(int));
    for(i=0;i<m;i++)
        ht[i]=-1;
    printf("Enter four digit key values (K) for N employee records:\n");
    for(i=0;i<n;i++)
        scanf("%d",&key[i]);
    for(i=0;i<n;i++)
    {
        if(count==m)
        {
            printf("\nHash table is full can't insert record %d key!!!",i+1);
            break;
        }
        insert(key[i]);
    }
    display();
}
