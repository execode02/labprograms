#include <stdio.h>
int main()
{
    char name[50];
    int units;
    float charge;
    printf("Enter the name of the consumer::");
    gets(name);
    printf("Enter the units consumed::");
    scanf("%d",&units);
    if(units<=200)
        charge=units*0.8+100;
    if(units>200&&units<=300)
        charge=(units-200)*0.9+260;
    if(units>300)
        charge=(units-300)*1+350;
    if(charge>400)
        charge=charge+(charge*0.15);
        printf("Total amount=%f\n",charge);
    return 0;
}
