#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0), curr = 0;

        for(int i=0;i<n;++i){
            curr += nums[i];

            if(sum - curr == 0)
                return i;

            sum -= nums[i];
        }

        return -1;
    }
};