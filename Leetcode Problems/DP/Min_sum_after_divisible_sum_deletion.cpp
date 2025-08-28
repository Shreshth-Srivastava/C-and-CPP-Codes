#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity --> O(N) ; Space Complexity --> O(K)

typedef long long ll;

class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        vector<ll> dp(k, LLONG_MAX);
        dp[0] = 0;
        ll res = 0;
        for (int a : nums) {
            res += a;
            res = dp[res % k] = min(dp[res % k], res);
        }
        return res;
    }
};