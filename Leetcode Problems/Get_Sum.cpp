#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity --> O(1) ; Space Complexity --> O(1)

class Solution {
public:
    int getSum(int a, int b) {
        int carry;
        while(b!=0){
            carry = (a&b)<<1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};