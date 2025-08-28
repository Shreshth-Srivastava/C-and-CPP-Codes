#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(min(money/7, children) ; Space Complexity --> O(1)

class Solution {
public:
    int distMoney(int money, int children) {
        if(money<children) return -1;
        if(money == children) return 0;
        if(money == 8*children) return children;
        if(money > 8*children) return children-1;
        int res = 0;
        money -= children;
        while(money>=7 && children>0){
            money -= 7;
            res++;
            children--;
        }
        if(money == 3 && children == 1) return res-1;          
        if(money >0 && children == 0) return res-1;          
        return res;
    }
};

