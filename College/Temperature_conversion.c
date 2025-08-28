///15
#include<stdio.h>
int main(void){
    int flag,a;
    float convert;
    printf("\n-------------------------------------------------------------");
    printf("\n-------------------------------------------------------------");
    printf("\nIn what unit would you like to input the temperature : ");
    printf("\n1.Celsius");
    printf("\n2.Fahrenheit");
    printf("\n-------------------------------------------------------------");
    printf("\n-------------------------------------------------------------");
    printf("\nEnter your choice : ");
    scanf("%d",&(flag));
    if(flag==1){
        float b=(9.0/5.0);
        printf("\nEnter the temperature in celsius : ");
        scanf("%d",&a);
        convert=(a*b)+32;
        printf("\nTemperature in fahrenheit : %f",convert);
    }
    else if(flag==2){
        float b=(5.0/9.0);
        printf("\nEnter the temperature in fahrenheit : ");
        scanf("%d",&a);
        convert=((a-32)*b);
        printf("\nTemperature in celsius : %f",convert);
    }
    else printf("\n!!!Invalid Input!!!");
    return 0;
}