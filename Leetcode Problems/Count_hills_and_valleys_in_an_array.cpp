#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0, n = nums.size();

        // Removing Duplicates
        int j = 1;

        for(int i=0;i<n-1;++i){
            if(nums[i] != nums[i+1]){
                nums[j] = nums[i+1];
                j++;
            }
        }

        for(int i=1;i<j-1;++i){
            int l = nums[i-1], r = nums[i+1];

            if((nums[i] > l && nums[i] > r) || (nums[i] < l && nums[i] < r))
                res++;
        }

        return res;
    }
};

// My Solution: Time Complexity--> O(N^2) ; Space Complexity --> O(1)

/*class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0;

        for(int i=1;i<nums.size()-1;++i){
            if(nums[i] == nums[i-1])
                continue;
            
            int l = left(i-1, nums[i], nums);
            int r = right(i+1, nums[i], nums);

            if(l == -1 || r == -1)
                continue;

            if((nums[i] > l && nums[i] > r) || (nums[i] < l && nums[i] < r))
                res++;
        }

        return res;
    }

private:
    int left(int idx, int val, vector<int>& nums){
        for(idx;idx >= 0;--idx){
            if(nums[idx] != val)
                return nums[idx];
        }

        return -1;
    }

    int right(int idx, int val, vector<int>& nums){
        for(idx;idx < nums.size();++idx){
            if(nums[idx] != val)
                return nums[idx];
        }

        return -1;
    }
};*/
