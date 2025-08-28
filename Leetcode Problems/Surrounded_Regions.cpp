#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// NeetCode DFS Solution --> Time Complexity: O(m x n) , Space Complexity: O(m x n)

class Solution {
public:
    int rows, cols;

    void solve(vector<vector<char>>& board) {
        rows = board.size(), cols = board[0].size();
        
        for(int r=0;r<rows;++r){
            if(board[r][0] == 'O'){
                save(board, r, 0);
            }
            if(board[r][cols-1] == 'O'){
                save(board, r, cols-1);
            }
        }

        for(int c=0;c<cols;++c){
            if(board[0][c] == 'O'){
                save(board, 0, c);
            }
            if(board[rows-1][c] == 'O'){
                save(board, rows-1, c);
            }
        }

        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
private:
    void save(vector<vector<char>>& board, int row, int col){
        if(row<0 || row>= rows || col<0 || col>=cols || board[row][col] != 'O') return;

        board[row][col] = 'T';

        save(board, row+1, col);
        save(board, row-1, col);
        save(board, row, col+1);
        save(board, row, col-1);
    }
};