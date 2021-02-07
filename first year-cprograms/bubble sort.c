#include <stdio.h>
int main()
{
    int a[100],n,i,j,temp;
    printf("enter the number of elements:");
    scanf("%d",&n);
    printf("enter the array elements in unsorted order:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("array elements before sorting:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n");
    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
    printf("array elements after sorting:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}
