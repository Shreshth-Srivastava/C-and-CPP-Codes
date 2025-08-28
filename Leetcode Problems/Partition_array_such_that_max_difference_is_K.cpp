#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution (Optimised)

class Solution {
public:
    int partitionArray(vector<int>& nums, int& k) {
        int res = 1, n = nums.size(), minElem = nums[0];

        sort(nums.begin(), nums.end());

        for(const auto& num: nums){
            minElem = min(minElem, num);

            if(num - minElem > k){
                res++;
                minElem = num;
            }
        }

        return res;
    }
};

// My Solution: Time Complexity --> O(NlogN) ; Space Complexity --> O(logN) for sorting

/*class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int res = 1, n = nums.size();

        sort(nums.begin(), nums.end());
        int maxElem = INT_MIN, minElem = INT_MAX;

        for(int i=0;i<n;i++){
            maxElem = max(maxElem, nums[i]);
            minElem = min(minElem, nums[i]);

            if(maxElem - minElem > k){
                res++;
                maxElem = nums[i];
                minElem = nums[i];
            }
        }

        return res;
    }
};*/

int main(){
    Solution sol;

    vector<int> nums = {2,2,4,5};
    int k = 0;

    cout<<sol.partitionArray(nums, k);

    return 0;
}