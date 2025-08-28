// Kadane's Algorithm is an efficient method to find the maximum sum of a contiguous subarray within a one-dimensional array of numbers. It works by iterating through the array while keeping track of the current subarray sum and the overall maximum found so far. At each element, the algorithm decides whether to extend the existing subarray or start a new one beginning at the current element. This is done by updating the current sum as the maximum of the current element and the current element plus the previous sum. The global maximum is then updated if the current sum exceeds it. The algorithm handles negative numbers gracefully by resetting the subarray when the sum drops below zero. It operates in linear time, O(n), making it highly efficient compared to brute-force approaches. Kadane’s Algorithm is especially useful in problems involving stock price changes, temperature variations, or any sequence where the goal is to find the best sub-interval. It’s simple to implement and forms a base for many advanced dynamic programming problems.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// The below code sample is for a specific ques (LeetCode - 152)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMin = 1, curMax = 1;

        for (int num : nums) {
            int tmp = curMax * num;
            curMax = max(max(num * curMax, num * curMin), num);
            curMin = min(min(tmp, num * curMin), num);
            res = max(res, curMax);
        }
        return res;
    }
};