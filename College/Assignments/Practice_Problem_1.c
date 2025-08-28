#include<stdio.h>
///1
/*int main(void){
    printf("\nSize of Integer in C : %d",sizeof(int));
    printf("\nSize of Short Integer in C : %d",sizeof(short int));
    printf("\nSize of Character in C : %d",sizeof(char));
    printf("\nSize of Float in C : %d",sizeof(float));
    printf("\nSize of Double in C : %d",sizeof(double));
    printf("\nSize of Long Double in C : %d",sizeof(long double));
    printf("\nSize of Void in C : %d",sizeof(void));
    return 0;
}*/
///2
/*#include<stdio.h>
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
}*/
///3
/*#include<stdio.h>
int main(void){
    float a;
    printf("\nEnter a number: ");
    scanf("%f",&a);
    if (a>0) printf("\nThe given value is a positive\n");
    if (a==0) printf("\nThe given value is equal to zero\n");
    if(a<0) printf("\nThe given value is negative");
    return 0;
}*/
///4
/*#include<stdio.h>
int main(void){
    float a;
    printf("\nEnter a number: ");
    scanf("%f",&a);
    printf("Multiplication Table of %f is as follows: ",a);
    for(int i=1;i<11;i++){
        printf("\n%f * %d = %f\n",a,i,(a*i));
    }
    return 0;
}*/
///5(a)
/*#include<stdio.h>
int main(void){
    float a,b,c;
    printf("\nEnter the value of the first number: ");
    scanf("%f",&a);
    printf("\nEnter the value of the second number: ");
    scanf("%f",&b);
    c=a;
    a=b;
    b=c;
    printf("\nValues after swap");
    printf("\nFirst value: %f",a);
    printf("\nSecond value: %f",b);
    return 0;
}*/
///5(b)
/*#include<stdio.h>
int main(void){
    float a,b;
    printf("\nEnter the value of the first number: ");
    scanf("%f",&a);
    printf("\nEnter the value of the second number: ");
    scanf("%f",&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("\nValues after swap");
    printf("\nFirst value: %f",a);
    printf("\nSecond value: %f",b);
    return 0;
}*/
///6
/*#include<stdio.h>
int main(void){
    int a,sum;
    printf("\nEnter an integer number: ");
    scanf("%d",&a);
    sum = a*(a+1)/2;
    printf("\nSum of all the numbers from 1 to the given number: %d",sum);
    return 0;
}*/
///7
/*#include<stdio.h>
int main(void){
    float a,b,c;
    printf("\nEnter the first value: ");
    scanf("%f",&a);
    printf("\nEnter the second value: ");
    scanf("%f",&b);
    c = a+b;
    printf("\nSum of inputted values: %f",c);
    return 0;
}*/
///8
/*#include<stdio.h>
int main(void){
    int a;
    printf("\nEnter an integer number: ");
    scanf("%d",&a);
    if(a%2==0) printf("\nEntered number is even");
    else printf("\nEntered number is odd"); 
    return 0;
}*/
///9
/*#include<stdio.h>
int main(void){
    float a,b,c,max;
    printf("\nEnter the first number: ");
    scanf("%f",&a);
    printf("\nEnter the second number: ");
    scanf("%f",&b);
    printf("\nEnter the third number: ");
    scanf("%f",&c);
    max=a;
    if(b>a) max = b;
    if(c>a) max = c;
    printf("\n%f is the maximum of the entered three numbers",max);
    return 0;
}*/
///10
/*#include<stdio.h>
int main(void){
    int a;
    printf("\nEnter year: ");
    scanf("%d",&a);
    if(a%4==0) printf("\nThe given year is a leap year");
    else printf("\nThe given year is not a leap year");
    return 0;
}*/
///11
/*#include<stdio.h>
int main(void){
    int a,factorial;
    printf("\nEnter an integer number: ");
    scanf("%d",&a);
    factorial = a;
    if(a == 0){
        printf("\nFactorial of 0 is equal to 1");
        return 0;
    }
    if(a<0){
        printf("\nFactorial of negative integers is not defined");
        return 0;
    }
    for(int i=a-1;i>0;i--){
        factorial = factorial * i;
    }
    printf("\nFactorial of %d is equal to %d",a,factorial);
    return 0;
}*/
///12
/*#include<stdio.h>
int main(void){
    int a;
    printf("\nEnter an integer number: ");
    scanf("%d",&a);
    for(int i=a-1;i>1;i--){
        if(a%i == 0){
            printf("\nThe given number is composite");
            return 0;
        }
    }
    printf("\nThe given number is prime");
    return 0;  
}*/
///13
/*#include<stdio.h>
int main(void){
    int a,count=0;
    printf("\nEnter an integer: ");
    scanf("%d",&a);
    if(a == 0){
        printf("\nNumber of digits in the given number is equal to 1");
        return 0;
    }
    while(a!=0){
        for(count;a!=0;count++){
            a=a/10;
        }
    }
    printf("\nNumber of digits in the given number is equal to %d",count);
    return 0;
}*/
///14
/*#include<stdio.h>
int main(void){
    int a,b,c,d,e;
    printf("\nEnter the first integer value: ");
    scanf("%d",&a);
    printf("\nEnter the second integer value: ");
    scanf("%d",&b);
    if(a>b){
        c=a;
        d=b;
    }
    if(b>a){
        c=b;
        d=a;
    }
    e=c%d;
    while(e!=0){
        c=d;
        d=e;
        e=c%d;   
    }
    printf("\nGCD of the given two numbers is %d",d);
    return 0;
}*/
///15
/*#include<stdio.h>
int main(void){
    int a,b,c=0;
    printf("\nEnter an integral value: ");
    scanf("%d",&a);
    while(a!=0){
        c=c*10;
        b=a%10;
        a=a/10;
        c=c+b;
    }
    printf("\nReverse of the given number : %d",c);
    return 0;
}*/
///16(a)
/*#include<stdio.h>
int main(void){
    for(int i=0;i<12;i++){
        printf("\n");
        for(int j=0;j<i+1;j++){
            printf("*");
        }
    }
    return 0;
}*/
///16(b)
/*#include<stdio.h>
int main(void){
    for(int i=0;i<12;i++){
        printf("\n");
        for(int j=0;j<12-i;j++){
            printf("*");
        }
    }
    return 0;
}*/
///16(c)
/*#include<stdio.h>
int main(void){
    for(int i=0;i<12;i++){
        printf("\n");
        for(int k=0;k<i+1;k++){
            printf(" ");
        }
        for(int j=0;j<12-i;j++){
            printf("*");
        }
    }
    return 0;
}*/
///16(d)
/*#include<stdio.h>
int main(void){
    for(int i=0;i<12;i++){
        printf("\n");
        for(int k=0;k<12-i;k++){
            printf(" ");
        }
        for(int j=0;j<i+1;j++){
            printf("*");
        }
    }
    return 0;
}*/