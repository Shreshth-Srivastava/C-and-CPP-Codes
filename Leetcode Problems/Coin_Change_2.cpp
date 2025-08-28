#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// NeetCode Solution (Bottom-Up Approach): Time Complexity --> O(N*T) ; Space Complexity --> O(T) ; where N is the length of the array coins and T is the amt

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(amount + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int a = 0; a <= amount; a++) {
                if (a >= coins[i]) {
                    dp[i][a] = dp[i + 1][a];
                    dp[i][a] += dp[i][a - coins[i]];
                }
            }
        }

        return dp[0][amount];
    }
};

int main(){
    Solution sol;
    vector<int> coins = {1,2,5};
    sol.change(5, coins);
    return 0;
}