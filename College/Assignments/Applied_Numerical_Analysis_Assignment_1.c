#include<stdio.h>
#include<math.h>
float func1(float a);
float func2(float b);
int main(){
    float array[11];
    array[0]=5;
    for(int i=1;i<11;i++){
        float e = func1(array[i-1]);
        float f = func2(array[i-1]);
        array[i]=array[i-1]-(e/f);
    }
    printf("\n2.");
    printf("\nIteration Number\tError(True value-the value at current iteration)\n");
    for(int j=1;j<9;j++) printf("\n\t%d\t\t\t\t%f",j,(3-array[j]));
    printf("\n3.");
    printf("\nIteration Number\t   E\n");
    for(int k=1;k<11;k++) printf("\n\t%d\t\t%f",k,(array[k]-array[k-1]));
    return 0;
}
float func1(float a){
    float c = pow(a,3);
    float g = pow(a,2);
    float h = c-4*g+a+6;
    return h; 
}
float func2(float b){
    float d = (pow(b,2));
    float i = 3*d-8*(b)+1;
    return i;
}