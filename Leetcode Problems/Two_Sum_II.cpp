#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int ptr1 = 0, ptr2 = n-1, sum;
        while(ptr1<ptr2){
            sum = numbers[ptr1] + numbers[ptr2];
            if(sum == target){
                return {ptr1+1, ptr2+1};
            }
            if(sum > target) ptr2--;
            else ptr1++;
        }
        return {};
    }
};