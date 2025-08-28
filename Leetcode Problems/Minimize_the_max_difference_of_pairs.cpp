#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Editorial Solution: Time Complexity --> O(nlogn + nlogV) ; Space Complexity --> O(logn) where V --> The max val in nums

class Solution {
public:
    // Find the number of valid pairs by greedy approach
    int countValidPairs(vector<int>& nums, int threshold) {
        int index = 0, count = 0;
        while (index < nums.size() - 1) {
            // If a valid pair is found, skip both numbers.
            if (nums[index + 1] - nums[index] <= threshold) {
                count++;
                index++;
            }
            index++;
        }
        return count;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = nums[n - 1] - nums[0];

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If there are enough pairs, look for a smaller threshold.
            // Otherwise, look for a larger threshold.
            if (countValidPairs(nums, mid) >= p) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main(){
    Solution sol;

    // vector<int> nums = {10,1,2,7,1,3};
    // int p = 2;

    // vector<int> nums = {4,2,1,2};
    // int p = 1;

    // vector<int> nums = {3,4,2,3,2,1,2};
    // int p = 3;

    // vector<int> nums = {3,4,2,3,2,1,2};
    // int p = 3;

    vector<int> nums = {8,9,1,5,4,3,6,4,3,7};
    int p = 4;

    cout<<sol.minimizeMax(nums, p);

    return 0;
}