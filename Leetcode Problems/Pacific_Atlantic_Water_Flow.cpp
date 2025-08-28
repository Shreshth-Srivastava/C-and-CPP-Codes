#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// NeetCode Solution ; Complexity Analysis --> Time: O(m x n) ; Space: O(m x n) where m->rows and n->cols

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for(int c=0;c<cols;++c){
            dfs(0, c, pacific, heights);
            dfs(rows-1, c, atlantic, heights);
        }

        for(int r=0;r<rows;++r){
            dfs(r, 0, pacific, heights);
            dfs(r, cols-1, atlantic, heights);
        }

        vector<vector<int>> res;

        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
            }
        }

        return res;
    }
private:
    vector<pair<int, int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        ocean[r][c] = true;
        for(auto [dr, dc] : directions){
            int nr = r + dr, nc = c + dc;
            if(nr>=0 && nr<heights.size() && nc>=0 && nc<heights[0].size() && heights[r][c] <= heights[nr][nc] && !ocean[nr][nc]){
                dfs(nr, nc, ocean, heights);
            }
        }
    }
};