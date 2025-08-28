#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = Next(n); // Using the concept of finding loop in a linked list
        while(slow != fast && fast != 1){
            slow = Next(slow);
            fast = Next(Next(fast));
        }
        if(fast == 1) return true;
        return false;
    }

    int Next(int n){
        int sum = 0;
        while(n > 0){
            int digit = n % 10;
            sum += pow(digit, 2);
            n /= 10;
        }
        return sum;
    }
};