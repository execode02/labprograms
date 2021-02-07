#include<stdio.h>
#include<stdlib.h>
int slength(char str[])
{
    int len=0;
    while(str[len]!='\0')
        len++;
    return len;
}
void scompare(char str1[],char str2[])
{
    int flag=0,i;
    if(slength(str1)!=slength(str2))
        flag=1;
    else
        for(i=0; i<slength(str1); i++)
            if(str1[i]!=str2[i])
            {
                flag=1;
                break;
            }
    if(flag==1)
        printf("both strings are not equal\n");
    else
        printf("both strings are equal\n");
}
void sconcat(char str1[],char str2[])
{
    char conc[50];
    int i,j;
    for(i=0; i<slength(str1); i++)
        conc[i]=str1[i];
    for(j=0; j<slength(str2); j++)
        conc[i++]=str2[j];
    conc[i]='\0';
    printf("concatenated string=%s\n",conc);
}
void main()
{
    char s1[50],s2[50];
    int len,choice;
    while(1)
    {
        printf("MAIN MENU\n");
        printf("1.string length\n2.compare string\n3.concatenate string\n4.exit\n");
        printf("enter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("enter string:");
            scanf("%s",s1);
            len=slength(s1);
            printf("length of %s=%d\n\n",s1,len);
            break;
        case 2:
            printf("enter string 1:");
            scanf("%s",s1);
            printf("enter string 2:");
            scanf("%s",s2);
            scompare(s1,s2);
            break;
        case 3:
            printf("enter string 1:");
            scanf("%s",s1);
            printf("enter string 2:");
            scanf("%s",s2);
            sconcat(s1,s2);
            break;
        case 4:
            exit(0);
        default:
            printf("invalid input\n");
            break;
        }
    }
}
