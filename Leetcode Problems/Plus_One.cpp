// I have solved this problem iteratively in C
// Here I have solved it recursively

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int N = digits.size();
        if(digits[N-1] != 9){
            digits[N-1]++;
            return digits;
        }
        add(digits, N-1);
        return digits;
    }

    void add(vector<int>& digits, int index){
        if(index == 0){
            if(digits[index] != 9){
                digits[index]++;
                return;
            }
            digits[index] = 1;
            digits.push_back(0);
            return;
        }
        if(digits[index] != 9){
            digits[index]++;
            return;
        }
        digits[index] = 0;
        add(digits, index-1);
    }
};