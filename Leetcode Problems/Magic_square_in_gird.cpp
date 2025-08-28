#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution

class Solution {
public:
    bool checkSum(vector<vector<int>> grid, int i, int j){
        int diagonal1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
        int diagonal2 = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];
        if(diagonal1 != diagonal2) return false;
        for(int ptr1 = i;ptr1<=i+2;ptr1++){
            int row = grid[ptr1][j] + grid[ptr1][j+1] + grid[ptr1][j+2];
            if(row != diagonal1) return false;
        }
        for(int ptr2 = j;ptr2<=j+2;ptr2++){
            int col = grid[i][ptr2] + grid[i+1][ptr2] + grid[i+2][ptr2];
            if(col != diagonal1) return false;
        }
        return true;
    }

    bool distinct(vector<vector<int>> grid, int i, int j){
        vector<int> temp(10,0);
        for(int ptr1 = i;ptr1 <= i+2;ptr1++){
            for(int ptr2 = j;ptr2 <= j+2;ptr2++){
                if(grid[ptr1][ptr2]>9) return false;
                temp[grid[ptr1][ptr2]]++;
                if(temp[grid[ptr1][ptr2]]>1) return false;
            }
        }
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int result = 0, rows = grid.size(), cols = grid[0].size();
        if(rows < 3 || cols < 3) return 0;
        for(int i = 0;i<=rows-3;i++){
            for(int j = 0;j<=cols-3;j++){
                if(grid[i+1][j+1] != 5) continue;
                if(grid[i][j]&1 != 0 || grid[i][j+2]&1 != 0 || grid[i+2][j]&1 != 0 || grid[i+2][j+2]&1 != 0) continue;
                if(distinct(grid, i, j)){
                    if(checkSum(grid, i, j)) result++;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{3,2,9,2,7},{6,1,8,4,2},{7,5,3,2,7},{2,9,4,9,6},{4,3,8,2,5}};
    cout<<sol.numMagicSquaresInside(grid);
    return 0;
}