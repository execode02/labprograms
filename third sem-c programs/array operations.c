#include <stdio.h>
#include <stdlib.h>
int a[50],pos,n,val,i;
void create()
{
    printf("Enter the size of the array::");
    scanf("%d",&n);
    printf("Enter the array elements::\n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
}
void display()
{
    for(i=0; i<n; i++)
        printf("%d\t",a[i]);
}
void insert()
{
    printf("Enter the position of the new element::");
    scanf("%d",&pos);
    printf("Enter the element::");
    scanf("%d",&val);
    for(i=n-1; i>=pos; i--)
        a[i+1]=a[i];
    n=n+1;
    a[pos]=val;
    printf("Array after insertion is::\n");
    display();
}
void delete()
{
    printf("Enter the position of the element to be deleted::");
    scanf("%d",&pos);
    for(i=pos; i<=n; i++)
        a[i]=a[i+1];
    n=n-1;
    printf("Array after deletion is::\n");
    display();
}
void main()
{
    int ch;
    create();
    while(1)
    {
        printf("\n____________MENU_____________\n1.insert\n2.delete\n3.display\n4.exit\n_____________________________\nEnter your choice::");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
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
