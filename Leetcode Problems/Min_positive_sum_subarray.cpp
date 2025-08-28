#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity --> O(N * (r-l+1)) --> O(N^2) ; Space Complexity --> O(N)

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        // Step 1: Compute prefix sums
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int minSum = INT_MAX;

        // Step 2: Iterate over all window sizes
        for (int k = l; k <= r; ++k) {
            // Sliding window over prefix sum
            for (int i = 0; i + k <= n; ++i) {
                int sum = prefix[i + k] - prefix[i]; // Subarray sum from i to i+k-1
                if (sum > 0) {
                    minSum = min(minSum, sum);
                }
            }
        }

        // Step 3: Return result
        return minSum != INT_MAX ? minSum : -1;
    }
};