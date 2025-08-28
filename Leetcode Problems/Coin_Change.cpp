#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// NeetCode Solution (Bottom-Up Approach) [Better Performance]: Time Complexity --> O(N*T) ; Space Complexity --> O(T) ; where N is the length of the array coins and T is the amt

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

// NeetCode Solution (Top-Down Approach): Time Complexity --> O(N*T) ; Space Complexity --> O(T) ; where N is the length of the array coins and T is the amt

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int minCoins = helper(coins, amount);
//         return minCoins == INT_MAX ? -1 : minCoins;
//     }

// private:
//     unordered_map<int, int> dp;
    
//     int helper(vector<int>& coins, int amount){
//         if(amount == 0) return 0;
//         if(dp.find(amount) != dp.end()) return dp[amount];
//         int res = INT_MAX;

//         for(const auto& coin: coins){
//             if(amount - coin >= 0){
//                 int result = helper(coins, amount-coin);
//                 if(result != INT_MAX){
//                     res = min(res, 1+result);
//                 }
//             }
//         }

//         dp[amount] = res;
//         return res;
//     }
// };

int main(){
    Solution sol;
    vector<int> coins = {1,2,5};
    sol.coinChange(coins, 11);
    return 0;
}