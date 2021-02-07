#include <stdio.h>
#include<math.h>
int main()
{
    float *ptr,std,sumstd=0,a[50],mean,sum=0;
    int n,i;
    printf("enter number of elements:");
    scanf("%d",&n);
    printf("enter array elements:\n");
    for(i=0;i<n;i++)
        scanf("%f",&a[i]);
    ptr=a;
    for(i=0;i<n;i++)
    {
        sum=sum+*ptr;
        ptr++;
    }
    mean=sum/n;
    ptr=a;
    for(i=0;i<n;i++)
    {
    sumstd=sumstd+pow((mean-*ptr),2);
    ptr++;
    }
    std=sqrt(sumstd/n);
    printf("sum=%f\nmean=%f\nstandard deviation=%f\n",sum,mean,std);
    return 0;
}
