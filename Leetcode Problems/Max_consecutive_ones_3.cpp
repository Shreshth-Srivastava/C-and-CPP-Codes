#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(1);

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, res = 0, curr = 0, n = nums.size();

        for(int r = 0;r<n;++r){
            if(nums[r] == 0)
                curr++;

            if(curr > k){
                while(nums[l] != 0)
                    l++;

                curr--;
                l++;
            }

            res = max(res, r-l+1);
        }

        res = max(res, curr);

        return res;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};

    cout<<sol.longestOnes(nums, 2);

    return 0;
}