#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rows(vector<vector<int>>& grid){
        int count = 0, n = grid.size();
        for(int i=0;i<n;i++){
            int ptr1 = 0, ptr2 = grid[0].size() - 1;
            while(ptr1<ptr2){
                if(grid[i][ptr1] != grid[i][ptr2]) count++;
                ptr1++;
                ptr2--;
            }
        }
        return count;
    }

    int cols(vector<vector<int>>& grid){
        int count = 0, n = grid[0].size();
        for(int i=0;i<n;i++){
            int ptr1 = 0, ptr2 = grid.size() - 1;
            while(ptr1<ptr2){
                if(grid[ptr1][i] != grid[ptr2][i]) count++;
                ptr1++;
                ptr2--;
            }
        }
        return count;
    }

    int minFlips(vector<vector<int>>& grid) {
        return min(rows(grid), cols(grid));
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{0,1},{0,1},{0,0}};
    sol.minFlips(grid);
    return 0;
}