#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0, n = nums.size();

        for(int i=0;i<n;++i){
            if(!(count&1) && nums[i] == 0){
                count++;
            }
            if((count&1) && nums[i] == 1){
                count++;
            }
        }
        return count;
    }
};