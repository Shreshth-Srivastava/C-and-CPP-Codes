#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Different Approach: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int freq=0,ans ;
    for(int num:nums){
        if(freq==0) ans = num;
        freq += (ans == num)?1:-1;
    }
    return ans;
    }
};

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();

        for(const auto& num: nums){
            m[num]++;
        }

        for(const auto& [key, val]: m){
            if(val > n/2)
                return key;
        }

        return -1;
    }
};