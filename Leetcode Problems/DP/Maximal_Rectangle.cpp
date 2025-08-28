#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// DP Approach: Time Complexity --> O(M*N) ; Space Complexity --> O(M*N)

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;

        const int m = matrix.size(), n = matrix[0].size();
        vector<int> left(n, 0), right(n, n), height(n, 0);
        int maxA = 0;

        for(int i=0;i<m;++i){
            int curr_left = 0, curr_right = n;

            for(int j=0;j<n;++j){
                if(matrix[i][j] == '1')
                    height[j]++;
                else height[j] = 0;
            }
            
            for(int j=0;j<n;++j){
                if(matrix[i][j] == '1')
                    left[j] = max(left[j], curr_left);
                else{
                    left[j] = 0;
                    curr_left = j+1;
                }
            }

            for(int j=n-1;j>=0;--j){
                if(matrix[i][j] == '1')
                    right[j] = min(right[j], curr_right);
                else{
                    right[j] = n;
                    curr_right = j;
                }
            }

            for(int j=0;j<n;++j)
                maxA = max(maxA, (right[j] - left[j])*height[j]);
        }

        return maxA;
    }
};