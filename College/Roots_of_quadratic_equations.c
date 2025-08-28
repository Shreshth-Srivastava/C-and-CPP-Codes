///16
#include<stdio.h>
#include<math.h>
int main(void){
    int a,b,c;
    float D,x,x1,x2;
    printf("General form of quadratic equation is a(x)^2 + bx + c=0");
    printf("\nEnter the value of a : ");
    scanf("%d",&a);
    if(a!=0){
        printf("\nEnter the value of b : ");
        scanf("%d",&b);
        printf("\nEnter the value of c : ");
        scanf("%d",&c);
        printf("\nInputted quadratic equation is as follows : ");
        printf("\n(%d)(x)^2 + (%d)x + (%d)",a,b,c);
        D=pow(b,2)-(4*a*c);
        if(D==0){
            printf("\nThe given quadratic equation has real and equal roots");
            x=((-b)/((2.0)*a));
            printf("\nBoth roots are %f",x);
        }
        else if(D>0){
            x1=((-b)+pow(D,(1.0/2.0)))/((2.0)*a);
            x2=((-b)-pow(D,(1.0/2.0)))/((2.0)*a);
            printf("\n%f",x1);
            printf("\n%f",x2);
        }
        else{
            printf("\nImaginary roots are as follows : ");
            printf("\n [%d + (%f)i]/(%d)",-b,pow(-D,(1.0/2.0)),((2)*a));
            printf("\n [%d - (%f)i]/(%d)",-b,pow(-D,(1.0/2.0)),((2)*a));
        }
    }
    else printf("\n !!!a cannot be zero!!!");
    return 0;
}