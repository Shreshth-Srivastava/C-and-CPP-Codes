#include<stdio.h>

int main(void){
    enum coin{penny, nickel, dime, quarter, half_dollar, dollar} money;
    money = dime;
    if(money == quarter) printf("\nMoney is a quarter.");
    else printf("\nMoney is not quarter.");
    return 0;
}