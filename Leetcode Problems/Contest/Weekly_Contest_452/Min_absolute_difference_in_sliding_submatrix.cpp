#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        unordered_set<int> s;
        vector<vector<int>> res;


        int rightShift = grid[0].size() - k;
        int downShift = grid.size() - k;

        vector<int> tempRow;

        for(int row = 0;row<=downShift;++row){
            for(int col = 0;col<=rightShift;++col){
                for(int i=row;i<row+k;++i){
                    for(int j=col;j<col+k;++j){
                        s.insert(grid[i][j]);
                    }
                }

                vector<int> temp;

                for(const auto& elem: s){
                    temp.push_back(elem);
                }

                int tempRes = INT_MAX;

                if(s.size() != 1){
                    for(int i=0;i<temp.size()-1;++i){
                        for(int j=i+1;j<temp.size();++j){
                            tempRes = min(tempRes, abs(temp[i] - temp[j]));
                        }
                    }
                }
                else{
                    tempRes = 0;
                }

                
                tempRow.push_back(tempRes);
                s.clear();
            }
            res.push_back(tempRow);
            tempRow.clear();
        }

        return res;
    }
};

int main(){
    Solution sol;
    // vector<vector<int>> grid = {{1,8},{3,-2}};
    // sol.minAbsDiff(grid, 2);

    // vector<vector<int>> grid = {{3,-1}};
    // sol.minAbsDiff(grid, 1);

    // vector<vector<int>> grid = {{1,-2,3},{2,3,5}};
    // sol.minAbsDiff(grid, 2);

    vector<vector<int>> grid = {{81274},{52541}};
    sol.minAbsDiff(grid, 1);

    return 0;
}