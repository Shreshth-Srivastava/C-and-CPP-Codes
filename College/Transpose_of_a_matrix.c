#include<stdio.h>

int main(void){
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
}