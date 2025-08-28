///11
#include<stdio.h>
int main(void){
    int order1=0;
    printf("\nEnter the order of first matrix : ");
    scanf("%d",&order1);
    int a[order1][order1];
    for(int i=0;i<order1;i++){
        for(int j=0;j<order1;j++){
            printf("\nEnter the value for(%d,%d) : ",(i+1),(j+1));
            scanf("%d",&(a[i][j]));
        }
    }
    printf("\nGiven matrix :-\n\n");
    for(int k=0;k<order1;k++){
        for(int l=0;l<order1;l++){
            printf("\t%d",a[k][l]);
        }
        printf("\n\n");
    }
    int order2=0;
    printf("\nEnter the order of second matrix : ");
    scanf("%d",&order2);
    int b[order2][order2];
    for(int i=0;i<order2;i++){
        for(int j=0;j<order2;j++){
            printf("\nEnter the value for(%d,%d) : ",(i+1),(j+1));
            scanf("%d",&(b[i][j]));
        }
    }
    printf("\nGiven matrix :-\n\n");
    for(int k=0;k<order2;k++){
        for(int l=0;l<order2;l++){
            printf("\t%d",b[k][l]);
        }
        printf("\n\n");
    }
    int flag=0;
    printf("-------------------------------------------------------------------");
    printf("\n-------------------------------------------------------------------");
    printf("\nWhat operation would you like to perform on these two matrices :-");
    printf("\n1. Addition");
    printf("\n2. Multiplication");
    printf("\n-------------------------------------------------------------------");
    printf("\n-------------------------------------------------------------------");
    printf("\nEnter your choice : ");
    scanf("%d",&(flag));
    if(flag==1){
        for(int i=0;i<order1;i++){
            for(int j=0;j<order2;j++){
                printf("\t%d",(a[i][j]+b[i][j]));
            }
            printf("\n\n");
        }
    }
    if(flag==2){
        for(int i=0;i<order1;i++){
        for(int j=0;j<order2;j++){
            int sum=0;
            for(int k=0;k<order1;k++){
                sum+=(a[i][k]*b[k][j]);
            }
            printf("\t%d",sum);
            }
        printf("\n\n");
        }
    }
return 0;
}