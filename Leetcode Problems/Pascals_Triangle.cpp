#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution, better runtime results

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=0;i<numRows;i++){
            vector<int> temp(i+1,1);
            for(int j=1;j<i;j++){
                temp[j] = result[i-1][j-1] + result[i-1][j];
            }
            result.push_back(temp);
        }
        return result;
    }
};

// Different Approach

/*class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        if (numRows == 1) return {{1}};
        
        vector<vector<int>> prevRows = generate(numRows - 1);
        vector<int> newRow(numRows, 1);
        
        for (int i = 1; i < numRows - 1; i++) {
            newRow[i] = prevRows.back()[i - 1] + prevRows.back()[i];
        }
        
        prevRows.push_back(newRow);
        return prevRows;
    }
};*/

int main(){
    Solution sol;
    sol.generate(5);
    return 0;
}