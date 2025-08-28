#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Neetcode Solution: Time Complexity --> O(m*n) ; Space Complexity --> O(m*n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[m-1][n-1] = 1;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                dp[i][j] += dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};

int main(){
    Solution sol;
    sol.uniquePaths(3, 7);
    return 0;
}