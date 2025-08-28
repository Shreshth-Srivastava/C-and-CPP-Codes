#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// NeetCode Solution | Complexity --> Time: O(m x n) ; Space: O(m x n)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), fresh = 0;
        queue<pair<int, int>> q;
        int result = -1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) fresh++;
            }
        }
        q.push({-1, -1});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(row == -1){
                result++;
                if(!q.empty()) q.push({-1, -1});
            }
            else{
                for(int i=0;i<4;i++){
                    int x = row + dirs[i][0];
                    int y = col + dirs[i][1];

                    if(x<0 || x>=m || y<0 || y>=n || grid[x][y] != 1) continue;

                    grid[x][y] = 2;
                    fresh--;
                    q.push({x, y});
                }
            }
        }
        if(fresh != 0) return -1;
        return result;
    }
private:
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
};