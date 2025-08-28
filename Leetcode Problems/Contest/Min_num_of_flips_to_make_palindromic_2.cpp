#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rows(vector<vector<int>>& grid){
        vector<vector<int>> temp = grid;
        int count = 0, n = temp.size();
        for(int i=0;i<n;i++){
            int ptr1 = 0, ptr2 = temp[0].size() - 1;
            while(ptr1<ptr2){
                if(temp[i][ptr1] != temp[i][ptr2]){
                    if(temp[i][ptr1] == 1) temp[i][ptr1] = 0;
                    else temp[i][ptr2] = 0;
                    count++;
                }
                ptr1++;
                ptr2--;
            }
        }
        return count+helper(temp);
    }

    int cols(vector<vector<int>>& grid){
        vector<vector<int>> temp = grid;
        int count = 0, n = temp[0].size();
        for(int i=0;i<n;i++){
            int ptr1 = 0, ptr2 = temp.size() - 1;
            while(ptr1<ptr2){
                if(temp[ptr1][i] != temp[ptr2][i]){
                    if(temp[ptr1][i] == 0) temp[ptr1][i] = 1;
                    else temp[ptr2][i] = 1;
                    count++;
                }
                ptr1++;
                ptr2--;
            }
        }
        return count+helper(temp);
    }

    int helper(vector<vector<int>>& grid){
        int n = grid.size(), result = 0;
        for(int i=0;i<n;i++){
            result += count(grid[i].begin(), grid[i].end(), 1);
        }
        return result%4;
    }

    int minFlips(vector<vector<int>>& grid) {
        return min(rows(grid), cols(grid));
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{1,0,1},{0,0,0},{0,0,0},{0,0,1}};
    cout<<sol.minFlips(grid);
    return 0;
}