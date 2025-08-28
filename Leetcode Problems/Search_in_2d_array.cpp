#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Slightly better approach
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int s = 0, e = m*n-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            int row = mid/n;
            int col = mid%n;
            if(matrix[row][col]==target)return 1;
            if(matrix[row][col]>target)e=mid-1;
            else s=mid+1;
        }
        return 0;
    }
};


// My Solution

/*class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int index = -1;
        for(int i=0;i<m;i++){
            if(target <= matrix[i][n-1]){
                index = i;
                break;
            }
        }
        if(index == -1) return false;
        int s = 0, e = n-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(matrix[index][mid] == target) return true;
            else if(matrix[index][mid] > target) e = mid-1;
            else s = mid+1;
        }
        return false;
    }
};*/