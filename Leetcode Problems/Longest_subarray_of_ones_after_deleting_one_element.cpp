#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Compelxity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0, l = 0, curr = 0, n = nums.size();

        for(int r = 0; r < n; ++r){
            if(nums[r] != 1)
                curr++;

            if(curr > 1){
                while(nums[l] == 1)
                    l++;
                
                curr--;
                l++;
            }

            res = max(res, r-l);
        }

        return res;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {1,1,0,0,1,1,1,0,1};
    cout<<sol.longestSubarray(nums);

    return 0;
}