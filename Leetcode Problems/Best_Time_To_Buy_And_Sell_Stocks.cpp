#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// NeetCode Solution (Top-Down): Time Complexity --> O(n) ; Space Complexity --> O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return helper(0, true, prices);
    }
private:
    unordered_map<string, int> dp;

    int helper(int i, bool buying, vector<int>& prices){
        if(i>=prices.size()) return 0;
        string key = to_string(i) + "-" + to_string(buying);
        if(dp.find(key) != dp.end()) return dp[key];

        int cooldown = helper(i+1, buying, prices);
        if(buying){
            int buy = helper(i+1, false, prices) - prices[i];
            dp[key] = max(cooldown, buy);
        }
        else{
            int sell = helper(i+2, true, prices) + prices[i];
            dp[key] = max(cooldown, sell);
        }

        return dp[key];
    }
};

// NeetCode Solution (Bottom-Up): Time Complexity --> O(n) ; Space Complexity --> O(n)

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n + 1, vector<int>(2, 0));  

//         for (int i = n - 1; i >= 0; --i) {
//             for (int buying = 1; buying >= 0; --buying) {
//                 if (buying == 1) {
//                     int buy = dp[i + 1][0] - prices[i];
//                     int cooldown = dp[i + 1][1];
//                     dp[i][1] = max(buy, cooldown);
//                 } else {
//                     int sell = (i + 2 < n) ? dp[i + 2][1] + prices[i] : prices[i];
//                     int cooldown = dp[i + 1][0];
//                     dp[i][0] = max(sell, cooldown);
//                 }
//             }
//         }

//         return dp[0][1];
//     }
// };

int main(){
    Solution sol;
    vector<int> prices = {1,2,3,0,2};
    sol.maxProfit(prices);
    return 0;
}