#include<stdio.h>
int numberofdigits(int num){
    int a,i;
    a = num;
    i=0;
    while(a>0){
        a = a/10;
        i++;
    }
    return i;
}

int countSymmetricIntegers(int low, int high){
    int ans = 0;
    int b = low;
    int c;
    int d;
    int e;
    int arr[10000];
    while(b<=high){
        c = numberofdigits(b);
        if(c%2 == 0){
            int f = 0;
            int g = 0;
            e = b;
            for(int j=0;j<c;j++){
                d = e%10;
                arr[j] = d;
                e = e/10;
            }
            for(int k=0;k<(c/2);k++){
                f = f+arr[k];
            }
            for(int l=(c/2);l<c;l++){
                g = g+arr[l];
            }
            if(f == g) ans++;
        }
        b++;
    }
    return ans;
}
int main(void){
    int a = 0;
    a = countSymmetricIntegers(1,100);
    printf("\nOutput: %d",a);
    return 0;
}