#include<stdio.h>
///1  
/*void pattern1(void);
void pattern2(void);
void pattern3(void);
void pattern4(void);
int main(void){
    pattern1();
    printf("\n");
    pattern2();
    printf("\n");
    pattern3();
    printf("\n");
    pattern4();
    return 0;
}
void pattern1(void){
    for(int i=1;i<5;i++){
        for(int j=1;j<=i;j++){
            printf("%d",j);
        }
        printf("\n");
    }
}
void pattern2(void){
    for(int i=1;i<5;i++){
        for(int j=1;j<=i;j++){
            printf("%d",i);
        }
        printf("\n");
    }
}
void pattern3(void){
    for(int i=1;i<5;i++){
        for(int j=i;j<5;j++) printf(" ");
        for(int k=1;k<=i;k++) printf("%d",k);
        if(i>1){
            int m=i-1;
            for(int l=1;l<i;l++){
                printf("%d",m);
                m--;
            }
        }
        printf("\n");
        }
    for(int n=1;n<4;n++){
        int q=1;
        for(int o=0;o<=n;o++) printf(" ");
        for(int p=1;p<=4-n;p++){
            printf("%d",q);
            q++;
        }
        for(int s=3-n;s>=1;s--){
            printf("%d",s);
        }
        printf("\n");
    }
}
void pattern4(void){
    for(int i=1;i<6;i++){
        for(int j=6-i;j>=1;j--) printf("%d",j);
        printf("\n");
    }
}*/
///2
/*void decimal_to_binary(void);
void binary_to_decimal(void);
int main(void){
    int a=0;
    printf("\nWhich operation would you like to choose : ");
    printf("\n----------------------------------------------");
    printf("\n----------------------------------------------");
    printf("\n1. Decimal to binary");
    printf("\n2. Binary to decimal");
    printf("\n----------------------------------------------");
    printf("\n----------------------------------------------");
    printf("\nEnter your choice : ");
    scanf("%d",&a);
    if(a==1) decimal_to_binary();
    else if(a==2) binary_to_decimal();
    else printf("\n!!!Invalid Input!!!");
    return 0;
}
void decimal_to_binary(void){
    int a=0,b=0,c=1,d=0,num=0;
    printf("\nEnter integer number : ");
    scanf("%d",&a);
    while(1){
        b=a%2;
        d=b*c;
        num=(num+d);
        c*=10;
        a=a/2;
        if(a==0) break;
    }
    printf("%d",num);
}
void binary_to_decimal(void){
    int a=0,b=0,c=1,d=0,num=0;
    printf("\nEnter a binary number : ");
    scanf("%d",&a);
    while(a>0){
        b=a%10;
        d=(b*c);
        c*=2;
        num=num+d;
        a=a/10;
    }
    printf("%d",num);
}*/
///3
/*void twovar(void);
void threevar(void);
int main(void){
    int flag,a,b;
    printf("\n---------------------------------------------------------\n");
    printf("---------------------------------------------------------\n");
    printf("How would you like to swap the numbers :- \n");
    printf("1. Using two variables\n");
    printf("2. Using three variables\n");
    printf("---------------------------------------------------------\n");
    printf("---------------------------------------------------------\n");
    printf("Enter your choice : ");
    scanf("%d",&flag);
    if(flag==1) twovar();
    else if(flag==2) threevar();
    else printf("\n!!!Invalid Input!!!");
    return 0;
}
void twovar(){
    int a,b;
    printf("\nEnter first number : ");
    scanf("%d",&a);
    printf("\nEnter second number : ");
    scanf("%d",&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("\nSwapped values are as follows : first value = %d , second value = %d",a,b);
}
void threevar(){
    int a,b,c;
    printf("\nEnter first number : ");
    scanf("%d",&a);
    printf("\nEnter second number : ");
    scanf("%d",&b);
    c=a;
    a=b;
    b=c;
    printf("\nSwapped values are as follows : first value = %d , second value = %d",a,b);
}*/
///4
/*#include<math.h>
int SI(void);
int CI(void);
int main(void){
    int flag;
    printf("\n---------------------------------------------------------");
    printf("\n---------------------------------------------------------");
    printf("\nWhat do you want to compute :-");
    printf("\n 1. Simple Interest");
    printf("\n 2. Compound Interest");
    printf("\n---------------------------------------------------------");
    printf("\n---------------------------------------------------------");
    printf("\nEnter your choice :");
    scanf("%d",&flag);
    if(flag==1) printf("%d",SI());
    else if(flag==2) printf("%d",CI());
    else printf("!!!Invalid Input!!!");
    return 0;
}
int SI(void){
    int p,t;float r;
    printf("\nEnter Principal Amount :");
    scanf("%d",&p);
    printf("\nEnter Annual Interest Rate :");
    scanf("%f",&r);
    printf("\nEnter Time in years :");
    scanf("%d",&t);
    return (p*r*t);
}
int CI(void){
    int p,n,t,x,y;float r;
    printf("\nEnter Principal Amount: ");
    scanf("%d",&p);
    printf("\nEnter Annual Interest Rate :");
    scanf("%f",&r);
    printf("\nEnter Time in years :");
    scanf("%d",&t);
    printf("\nEnter number of times interest is compounded per year :");
    scanf("%d",&n);
    x=(1+(r/n));
    y=pow(x,(n*t));
    return (p*y-p);
}*/
///6
/*int GCD(int num1,int num2);
int LCM(int num1,int num2);
int main(void){
    int flag,a,b;
    printf("\nEnter first number : ");
    scanf("%d",&a);
    printf("\nEnter second number : ");
    scanf("%d",&b);
    printf("\n---------------------------------------------------------");
    printf("\n---------------------------------------------------------");
    printf("\nWhat do you find :-");
    printf("\n 1. GCD of these two numbers");
    printf("\n 2. LCM of these two numbers");
    printf("\n---------------------------------------------------------");
    printf("\n---------------------------------------------------------");
    printf("\nEnter your choice : ");
    scanf("%d",&flag);
    if(flag==1) printf("%d",GCD(a,b));
    else if(flag==2) printf("%d",LCM(a,b));
    else printf("!!!Invalid Input!!!");
    return 0;
}
int GCD(int num1,int num2){
    int r;
    while(r>0){
        if(num1>num2){
            r=(num1)%(num2);
            num1=num2;
            if(r==0) return num2;
            num2=r;
        }
        if(num2>num1){
            r=(num2)%(num1);
            num2=num1;
            if(r==0) return num1;
            num1=r;
        }
    }
}
int LCM(int num1,int num2){
    return (((num1)*(num2))/(GCD(num1,num2)));
}*/
///7
/*int main(void){
    int a,year;
    printf("Enter year : ");
    scanf("%d",&year);
    a=((year%4)==0)?1:0;
    (a==1)?printf("It's a leap year"):printf("It's not a leap year");
    return 0;
}*/
///8
/*int main(void){
    int a[10],max,min;
    printf("\nEnter ten numbers :-");
    for(int i=0;i<10;i++){
        printf("\nNumber %d : ",(i+1));
        scanf("%d",&(a[i]));
    }
    max=a[0];
    min=a[0];
    for(int j=1;j<10;j++){
        if(max<a[j]) max=a[j];
        if(min>a[j]) min=a[j];
    }
    printf("\nMaximum of the given numbers is %d",max);
    printf("\nMinimum of the given number is %d",min);
    return 0;
}*/
///9
/*int main(void){
    int i=50,j,k;
    printf("\nPrime numbers between 50 and 150 are as follows :-");
    for(i;i<151;i++){
        for(j=2;j<i;j++){
            k=0;
            if(i%j==0){
                k++;
                break;
            }
        }
        if(k==0) printf("\n%d",i);
    }
    return 0;
}*/
///10
/*int main(void){
    int order=0;
    printf("\nEnter the order of the matrix : ");
    scanf("%d",&order);
    int a[order][order];
    for(int i=0;i<order;i++){
        for(int j=0;j<order;j++){
            printf("\nEnter the value for(%d,%d) : ",(i+1),(j+1));
            scanf("%d",&(a[i][j]));
        }
    }
    printf("\nGiven matrix :-\n\n");
    for(int k=0;k<order;k++){
        for(int l=0;l<order;l++){
            printf("\t%d",a[k][l]);
        }
        printf("\n\n");
    }
    for(int b=0;b<order-1;b++){
        for(int c=b+1;c<order;c++){
            if(b!=c){
                a[b][c]=(a[b][c])+(a[c][b]);
                a[c][b]=(a[b][c])-(a[c][b]);
                a[b][c]=(a[b][c])-(a[c][b]);
            }
        }
    }
    printf("\nTranspose of the given matrix :-\n\n");
    for(int d=0;d<order;d++){
        for(int e=0;e<order;e++){
            printf("\t%d",a[d][e]);
        }
        printf("\n\n");
    }
    return 0;
}*/