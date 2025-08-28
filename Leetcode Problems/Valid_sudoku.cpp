#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Solution

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int cnt = 9;
        bool row[cnt][cnt] = {false};
        bool col[cnt][cnt] = {false};
        bool sub[cnt][cnt] = {false};
        
        for(int r = 0; r < cnt; ++r){
            for(int c = 0; c < cnt; ++c){
                if(board[r][c] == '.')
                    continue;
                
                int idx = board[r][c] - '0' - 1;
                int area = (r/3) * 3 + (c/3);
                
                if(row[r][idx] || col[c][idx] || sub[area][idx]){
                    return false;
                }
                
                row[r][idx] = true;
                col[c][idx] = true;
                sub[area][idx] = true;
            }
        }
        return true;
    }
};

// Incomplete Solution

/*class Solution {
public:
    bool checkRow(vector<vector<char>>& board, char target, int row, int col){
        for(int i=row+1;i<9;i++){
            if(board[i][col] == target) return false;
        }
        return true;
    }

    bool checkCol(vector<vector<char>>& board, char target, int row, int col){
        for(int i=col+1;i<9;i++){
            if(board[row][i] == target) return false;
        }
        return true;
    }

    bool checkCell(vector<vector<char>>& board, char target, int row, int col){
        int tempRow = row%3, tempCol = col%3;
        for(int i=tempRow;i<3;i++){
            for(int j=tempCol;j<3;j++){
                if(board[row+i][col+j] == target) return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    // Checking rows
                    if(!checkRow(board, board[i][j], i, j)) return false;
                    // Checking cols
                    if(!checkCol(board, board[i][j], i, j)) return false;
                    // Checking cell
                    if(!checkCell(board, board[i][j], i, j)) return false;
                }
            }
        }
        return true;
    }
};*/

int main(){
    Solution sol;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}
    };
    cout<<"Result: "<<sol.isValidSudoku(board)<<endl;
    return 0;
}