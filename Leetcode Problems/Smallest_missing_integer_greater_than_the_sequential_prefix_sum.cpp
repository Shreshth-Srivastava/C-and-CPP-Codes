#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Solution: Time Complexity --> O(NlogN) ; Space Complexity --> (logN)

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        for (int i = 1; i< nums.size(); i++) {
            if (nums[i] == nums[i-1]+1) sum += nums[i];
            else break;
        }
        sort(nums.begin(), nums.end());

        for (int i = 0; i< nums.size(); i++) {
            if (sum == nums[i]) sum++;
        }

        return sum;
    }
};

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

/*class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size(), maxSum = nums[0];

        bool arr[1276] = {false};
        for(const auto& num: nums)
            arr[num] = true;

        for(int r = 1;(r < n) && (nums[r] == nums[r-1] + 1);++r){
            maxSum += nums[r];
        }

        for(;arr[maxSum];maxSum++);

        return maxSum;

    }
};*/