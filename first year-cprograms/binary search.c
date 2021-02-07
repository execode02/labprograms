#include <stdio.h>
int main()
{
    int high,mid,low,n,a[50],key,found=0,i;
    printf("enter the number of elements:");
    scanf("%d",&n);
    printf("enter the array elements in sorted order:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("enter the number to be searched:");
    scanf("%d",&key);
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key==a[mid])
        {
            found=1;
            break;
        }
        else if(key>a[mid])
            low=mid+1;
        else
            high=mid-1;
    }
    if(found==1)
        printf("the entered element %d is found in %d position\n",key,mid+1);
    else
        printf("the entered element %d is not found\n",key);
    return 0;
}
