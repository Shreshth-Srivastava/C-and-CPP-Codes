#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(MxN) ; Space Complexity --> O(MxN)

class Solution {
    int MOD = 1e9 + 7;
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<vector<pair<int,int>>> dp(m+1, vector<pair<int,int>>(n+1, {-1,-1}));
        return dfs({0,0}, grid, m, n, 1, dp) % MOD;
    }
private:
    int dfs(pair<int, int> curr, vector<vector<int>>& grid, int m, int n, int dir, vector<vector<pair<int,int>>>& dp){
        if(curr.first < 0 || curr.first >= m || curr.second < 0 || curr.second >= n)
            return 0;

        if(curr.first == m-1 && curr.second == n-1)
            return 1;

        if(grid[curr.first][curr.second] == 1){
            if(dir){
                if(curr.first < m  && dp[curr.first][curr.second].first != -1){
                    return dp[curr.first][curr.second].first;
                }
                
                int down = dfs({curr.first + 1, curr.second}, grid, m, n, 0, dp);
                dp[curr.first][curr.second].first = (down % MOD) % MOD;
                return (down % MOD) % MOD;
            }
            else{
                if(curr.second < n && dp[curr.first][curr.second].second != -1){
                    return dp[curr.first][curr.second].second;
                }
                
                int right = dfs({curr.first, curr.second + 1}, grid, m, n, 1, dp);
                dp[curr.first][curr.second].second = (right % MOD) % MOD;
                return (right % MOD) % MOD;
            }
        }

        if(dp[curr.first][curr.second].first != -1)
            return dp[curr.first][curr.second].first;
        
        int right = dfs({curr.first, curr.second + 1}, grid, m, n, 1, dp);
        int down = dfs({curr.first + 1, curr.second}, grid, m, n, 0, dp);
        
        dp[curr.first][curr.second].first = ((right % MOD) + (down % MOD)) % MOD;
        dp[curr.first][curr.second].second = ((right % MOD) + (down % MOD)) % MOD;

        return ((right % MOD) + (down % MOD)) % MOD;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> grid = {{0,1,1},{1,1,0}};
    cout<<sol.uniquePaths(grid);

    return 0;
}