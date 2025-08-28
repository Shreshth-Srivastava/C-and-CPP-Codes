#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        const int n = nums.size();
        int p = 1, q = 2;

        for(p;p<n;++p){
            if(nums[p] <= nums[p-1]){
                p--;
                break;
            }
        }

        if(p == 0)
            return false;

        for(q=p+1;q<n;++q){
            if(nums[q] >= nums[q-1]){
                q--;
                break;
            }
        }

        if(q >= n-1)
            return false;

        for(int i=q+1;i<n;++i){
            if(nums[i] <= nums[i-1])
                return false;
        }

        return true;
    }
};