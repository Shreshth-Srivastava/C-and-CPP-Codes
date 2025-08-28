///#include<stdio.h>
/*int main(void){
    for(int i=0;i<6;i++){
        for(int j=1;j<=i;j++){
            printf("%d",j);
        }
        printf("\n");
    }
    return 0;
}*/
/*int main(void){
    for(int i=0;i<6;i++){
        for(int j=1;j<=i;j++){
            printf("%d",i);
        }
        printf("\n");
    }
    return 0;
}*/
/*int main(void){
    int sum=1;
    for(int i=0;i<5;i++){
        for(int j=1;j<=i;j++){
            printf("%d",sum);
            sum++;
        }
        printf("\n");
    }
    return 0;
}*/
/*int main(void){
    for(int i=1;i<11;i++) printf("\n%d",i);
    return 0;
}*/
/*int main(void){
    int sum=0;
    for(int i=0;i<11;i++) sum+=i;
    printf("%d",sum);
    return 0;
}*/
/*int main(void){
    int a[10],sum=0;
    float avg;
    for(int i=0;i<10;i++){
        printf("Enter number : ");
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    avg=sum/10.0;
    printf("Sum is : %d\n",sum);
    printf("Average is : %f",avg);
    return 0;
}*/
/*int main(void){
    int a[10],sq,cb;
    for(int i=0;i<10;i++){
        printf("Enter a number : ");
        scanf("%d",&a[i]);
    }
    printf("\nSquares\n");
    for(int j=0;j<10;j++){
        sq=(a[j])*(a[j]);
        printf("%d",sq);
        printf("\n");
    }
    printf("\nCubes\n");
    for(int k=0;k<10;k++){
        cb=(a[k])*(a[k])*(a[k]);
        printf("%d",cb);
        printf("\n");
    }
    return 0;
}*/
#include<stdio.h>
int main(void){
    while(1){
        float a,b;
        int c=0;
        printf("\nEnter the first value : ");
        scanf("%f",&a);
        printf("\nEnter the second value :  ");
        scanf("%f",&b);
        printf("\n--------------------------------------------------------------");
        printf("\n--------------------------------------------------------------");
        printf("\nWhat to do with these two value");
        printf("\n1. Add");
        printf("\n2. Subtract");
        printf("\n3. Multiply");
        printf("\n4. Divide");
        printf("\n5. Exit");
        printf("\n--------------------------------------------------------------");
        printf("\n--------------------------------------------------------------");
        printf("\nEnter your choice : ");
        scanf("%d",&c);
        if(c==1) printf("\nAddition : %f",(a+b));
        else if(c==2) printf("\nSubtraction : %f",(a-b));
        else if(c==3) printf("\nMultiplicatiion : %f",(a*b));
        else if(c==4){
            if(b==0) printf("\n!!!Zero division error!!!\n");
            else printf("\nDivision : %f",(a/b));
        }
        else if(c==5) break;
        else printf("\n!!!Invalid Input!!!");
    }
    return 0;
}