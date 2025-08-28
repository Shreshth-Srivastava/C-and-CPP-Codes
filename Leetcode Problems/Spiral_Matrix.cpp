#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(m*n) ; Space Complexity --> O(1) and O(m*n) for output 

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int firstRow = 0, firstCol = 0, lastRow = matrix.size()-1, lastCol = matrix[0].size()-1;
        vector<int> res;
        int n = (lastRow+1) * (lastCol+1);
        while(res.size() < n){
            for(int i=firstCol;i<=lastCol;i++){
                res.push_back(matrix[firstRow][i]);
            }
            firstRow++;

            for(int i=firstRow;i<=lastRow;i++){
                res.push_back(matrix[i][lastCol]);
            }
            lastCol--;

            if (!(res.size() < n)) {
                break;
            }

            for(int i=lastCol;i>=firstCol;i--){
                res.push_back(matrix[lastRow][i]);
            }
            lastRow--;

            for(int i=lastRow;i>=firstRow;i--){
                res.push_back(matrix[i][firstCol]);
            }
            firstCol++;
        }
        
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    sol.spiralOrder(matrix);
    return 0;
}