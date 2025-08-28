#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> res;
        if(numWays[0] == 1)
            res.push_back(1);

        for(int i=1;i<numWays.size();++i){
            // if(numWays[i] == 0)
            //     continue;

            if(helper(res, i+1) != numWays[i]){
                res.push_back(i+1);
                if(res.size() > 0 && helper(res, i+1) != numWays[i])
                    return {};
            }
        }

        return res;
    }
private:
    int helper(vector<int>& coins, int amt){
        int n = coins.size();
        if(n == 0) return -1;

        vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(amt + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int a = 0; a <= amt; a++) {
                if (a >= coins[i]) {
                    dp[i][a] = dp[i + 1][a];
                    dp[i][a] += dp[i][a - coins[i]];
                }
            }
        }

        return dp[0][amt];
    }
};

int main(){
    Solution sol;

    // vector<int> nums = {0,1,0,2,0,3,0,4,0,5};
    vector<int> nums = {0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0};
    sol.findCoins(nums);

    return 0;
}