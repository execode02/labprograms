#include <stdio.h>
#include <stdlib.h>
void main()
{
    char STR[100],PAT[100],REP[100],ANS[100];
    int i,c,m,k,flag=0,j;
    printf("Enter the main string::");
    gets(STR);
    printf("Enter the pattern string::");
    gets(PAT);
    printf("Enter the replace string::");
    gets(REP);
    i=m=c=j=0;
    while(STR[c]!='\0')
    {
        if(STR[m]==PAT[i])
        {
            i++;
            m++;
            if(PAT[i]=='\0')
            {
                flag=1;
                for(k=0;REP[k]!='\0';k++,j++)
                    ANS[j]=REP[k];
                i=0;
                c=m;
            }
        }
        else
        {
            ANS[j]=STR[c];
            j++;
            c++;
            m=c;
            i=0;
        }
    }
    if(flag==0)
        printf("Pattern does not found!!!");
    else
    {
        ANS[j]='\0';
        printf("The resultant string is \n%s\n",ANS);
    }
}
