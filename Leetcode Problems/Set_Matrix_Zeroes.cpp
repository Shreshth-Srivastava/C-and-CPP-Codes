#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Solution-1: Time Complexity --> O(m*n) ; Space Complexity --> O(m+n);

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int N = matrix.size(), M = matrix[0].size();
//         vector<bool> row(N, false);
//         vector<bool> col(M, false);

//         for(int i=0;i<N;i++){
//             for(int j=0;j<M;j++){
//                 if(matrix[i][j] == 0){
//                     row[i] = true;
//                     col[j] = true;
//                 }
//             }
//         }

//         for (int r = 0; r < N; ++r) {
//             for (int c = 0; c < M; ++c) {
//                 if (row[r] || col[c]) {
//                     matrix[r][c] = 0;
//                 }
//             }
//         }
//     }
// };

// Solution-2: Time Complexity --> O(m*n) ; Space Complexity --> O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        bool rowZero = false;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    if (r > 0) {
                        matrix[r][0] = 0;
                    } else {
                        rowZero = true;
                    }
                }
            }
        }

        for (int r = 1; r < ROWS; r++) {
            for (int c = 1; c < COLS; c++) {
                if (matrix[0][c] == 0 || matrix[r][0] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int r = 0; r < ROWS; r++) {
                matrix[r][0] = 0;
            }
        }

        if (rowZero) {
            for (int c = 0; c < COLS; c++) {
                matrix[0][c] = 0;
            }
        }
    }
};