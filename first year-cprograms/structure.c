#include <stdio.h>
struct student
{
    char usn[10];
    char name[50];
    int marks;
};
int main()
{
    struct student s[10];
    int countav=0,countbv=0,sum=0,n,i;
    float average;
    printf("enter number of students:");
    scanf("%d",&n);
    printf("enter student details:\n");
    for(i=0;i<n;i++)
    {
        printf("enter USN:");
        scanf("%s",&s[i].usn);
        printf("enter name:");
        scanf("%s",&s[i].name);
        printf("enter marks:");
        scanf("%d",&s[i].marks);
        printf("\n");
    }
    printf("displaying information:\n");
    for(i=0;i<n;i++)
    {
        printf("USN:%s\n",s[i].usn);
        printf("name:%s\n",s[i].name);
        printf("marks:%d",s[i].marks);
        printf("\n");
    }
    for(i=0;i<n;i++)
    {
        sum=sum+s[i].marks;
    }
    average=sum/n;
    for(i=0;i<n;i++)
    {
        if(s[i].marks>=average)
            countav++;
        else
            countbv++;
    }
    printf("average marks of students=%f\n",average);
    printf("total number of students above average=%d\n",countav);
    printf("total number of students below average=%d\n",countbv);
    return 0;
}
