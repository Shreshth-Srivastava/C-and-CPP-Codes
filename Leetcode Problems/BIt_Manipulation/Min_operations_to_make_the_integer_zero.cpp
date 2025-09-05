#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// Time Complexity --> O(lognum1) ; Space Complexity --> O(1)

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int res = 1;

        while(1){
            ll temp = num1 - static_cast<ll>(num2) * res;
            
            if(temp < res)
                return -1;

            if(res >= __builtin_popcountll(temp))
                return res;
            
            res++;
        }

        return res;
    }
};