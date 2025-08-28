#include<stdio.h>

void Addition(void){
    int order;
    printf("\nEnter the order of both the matrices: ");
    scanf("%d",&order);
    int arr1[order][order];
    int arr2[order][order];
    printf("\nEnter the data for the first matrix:-");
    for(int i = 0;i < order;i++){
        for(int j = 0;j < order;j++){
            printf("\nEnter the value for (%d,%d): ",i+1,j+1);
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("\nEnter the data for the second matrix:-");
    for(int i = 0;i < order;i++){
        for(int j = 0;j < order;j++){
            printf("\nEnter the value for (%d,%d): ",i+1,j+1);
            scanf("%d",&arr2[i][j]);
        }
    }
    printf("\nResult:-\n\n");
    for(int i=0;i<order;i++){
        for(int j=0;j<order;j++){
            printf("\t%d",(arr1[i][j]+arr2[i][j]));
        }
        printf("\n\n");
    }
}

void Subtraction(void){
    int order;
    printf("\nEnter the order of both the matrices: ");
    scanf("%d",&order);
    int arr1[order][order];
    int arr2[order][order];
    printf("\nEnter the data for the first matrix:-");
    for(int i = 0;i < order;i++){
        for(int j = 0;j < order;j++){
            printf("\nEnter the value for (%d,%d): ",i+1,j+1);
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("\nEnter the data for the second matrix:-");
    for(int i = 0;i < order;i++){
        for(int j = 0;j < order;j++){
            printf("\nEnter the value for (%d,%d): ",i+1,j+1);
            scanf("%d",&arr2[i][j]);
        }
    }
    printf("\nResult:-\n\n");
    for(int i=0;i<order;i++){
        for(int j=0;j<order;j++){
            printf("\t%d",(arr1[i][j]-arr2[i][j]));
            }
        printf("\n\n");
        }
}

void Multiplication(void){
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
    printf("\nResult :-\n\n");
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

int main(void){
    int a;
    while(1){
        printf("\n|-----------------------------------------------------|");
        printf("\n|-----------------------------------------------------|");
        printf("\n|\t\t\tMenu");
        printf("\n|-----------------------------------------------------|");
        printf("\n|-----------------------------------------------------|");
        printf("\n1. Addition");
        printf("\n2. Subtraction");
        printf("\n3. Multiplication");
        printf("\n4. Exit");
        printf("\nEnter your choice (1/2/3): ");
        scanf("%d",&a);
        if(a == 1) Addition();
        else{
            if(a == 2) Subtraction();
            else{
                if(a == 3) Multiplication();
                else{
                    if(a == 4) break;
                    else printf("\n!!Invalid Input!!");
                }
            }
        }
    }
    return 0;
}