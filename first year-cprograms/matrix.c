#include <stdio.h>
int main()
{
    int m,n,p,q,i,j,k,a[10][10],b[10][10],c[10][10];
    printf("enter the order of first matrix:");
    scanf("%d%d",&m,&n);
    printf("enter the order of second matrix:");
    scanf("%d%d",&p,&q);
    if(n!=p)
        printf("matrix multiplication is not possible\n");
    else
    {
        printf("enter %d elements into matrix A:\n",m*n);
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        printf("enter %d elements into matrix B:\n",p*q);
        for(i=0; i<p; i++)
            for(j=0; j<q; j++)
                scanf("%d",&b[i][j]);
        printf("matrix A:\n");
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
                printf("%d\t",a[i][j]);
            printf("\n");
        }
        printf("matrix B:\n");
        for(i=0; i<p; i++)
        {
            for(j=0; j<q; j++)
                printf("%d\t",b[i][j]);
            printf("\n");
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<q; j++)
            {
                c[i][j]=0;
                for(k=0; k<n; k++)
                    c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }

        printf("matrix C:\n");
        for(i=0; i<m; i++)
        {
            for(j=0; j<q; j++)
                printf("%d\t",c[i][j]);
            printf("\n");
        }
    }
    return 0;
}
