#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Solution

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int i = rStart, j = cStart;
        int diri = 0, dirj = 1; // directions to move
        int twice = 2;
        vector<vector<int>> res;
        int moves = 1;
        int next_moves = 2;

        while (res.size() < rows * cols) {
            if (i >= 0 && i < rows && j >= 0 && j < cols) {
                res.push_back({i, j});
            }

            i += diri;
            j += dirj;
            moves -= 1;
            if (moves == 0) {
                int temp = diri;
                diri = dirj;
                dirj = -temp; // right direction
                twice -= 1;
                if (twice == 0) {
                    twice = 2;
                    moves = next_moves;
                    next_moves += 1;
                } else {
                    moves = next_moves - 1;
                }
            }
        }
        return res;
    }
};

// My Incomplete Solution

/*class Solution {
public:
    void helper(int rows, int cols, int& counter, string& dir, int& rStart, int& cStart, vector<vector<int>>& result,vector<vector<bool>>& temp){
        if(rStart >= 0 && rStart < rows && cStart < cols && cStart >=0 && !temp[rStart][cStart]){
            result.push_back({rStart, cStart});
            counter++;
            temp[rStart][cStart] = true;
        }

        if(counter == rows*cols) return;

        if(dir == "down"){
            if(cStart - 1 >= 0 && !temp[rStart][cStart-1]){
                dir = "left";
                cStart--;
            }
            else rStart++;
        }

        else if(dir == "left"){
            if(rStart - 1 >= 0 && !temp[rStart-1][cStart]){
                dir = "up";
                rStart--;
            }
            else cStart--;
        }

        else if(dir == "up"){
            if(cStart + 1 < cols && !temp[rStart][cStart+1]){
                dir = "right";
                cStart++;
            }
            else rStart--;
        }
        else{
            if(rStart + 1 < rows && !temp[rStart+1][cStart] && counter>1){
                dir = "down";
                rStart++;
            }
            else if(rStart+1 == rows && counter>1){
                
            }
            else cStart++;
        }

        if(cStart == cols){
            cStart--;
            while(temp[rStart][cStart]){
                rStart++;
                dir = "left";
                if(rStart == rows) break;
            }
        }

        if(cStart == -1){
            cStart++;
            while(temp[rStart][cStart]){
                rStart--;
                dir = "up";
                if(rStart == -1) break;
            }
        }

        if(rStart == -1){
            rStart++;
            while(temp[rStart][cStart]){
                cStart++;
                dir = "right";
                if(cStart == cols) break;
            }
        }

        if(rStart == rows){
            rStart--;
            while(temp[rStart][cStart]){
                cStart--;
                dir = "left";
                if(cStart == -1) break;
            }
        }

        helper(rows, cols, counter, dir, rStart, cStart, result, temp);
    }

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        vector<vector<bool>> temp(rows, vector<bool>(cols, false));
        int counter = 0;
        string dir = "right";
        helper(rows, cols, counter, dir, rStart, cStart, result, temp);
        while(counter != rows*cols){
            if(rStart >= 0 && rStart < rows && cStart < cols && cStart >=0 && !temp[rStart][cStart]){
                result.push_back({rStart, cStart});
                counter++;
                temp[rStart][cStart] = true;
                if(dir == "right") cStart++;
                else if(dir == "left") cStart--;
                else if(dir == "up") rStart--;
                else rStart++;
            }

            if(cStart == cols){
                cStart--;
                while(temp[rStart][cStart]){
                    rStart++;
                    dir = "left";
                    if(rStart == rows) break;
                }
            }

            if(cStart == -1){
                cStart++;
                while(temp[rStart][cStart]){
                    rStart--;
                    dir = "up";
                    if(rStart == rows) break;
                }
            }

            if(rStart == -1){
                rStart++;
                while(temp[rStart][cStart]){
                    cStart++;
                    dir = "right";
                    if(cStart == cols) break;
                }
            }

            if(rStart == rows){
                rStart--;
                while(temp[rStart][cStart]){
                    cStart--;
                    dir = "left";
                    if(cStart == -1) break;
                }
            }

            if(dir == "down"){
                if(cStart - 1 < rows && !temp[rStart][cStart-1]){
                    result.push_back({rStart, cStart});
                    temp[rStart][cStart] = true;
                    counter++;
                    dir = "left";
                    cStart--;
                }
            }

            else if(dir == "left"){
                if(rStart - 1 >= 0 && !temp[rStart-1][cStart]){
                    result.push_back({rStart, cStart});
                    temp[rStart][cStart] = true;
                    counter++;
                    dir = "up";
                    rStart--;
                }
            }

            else if(dir == "up"){
                if(cStart + 1 < cols && !temp[rStart][cStart+1]){
                    result.push_back({rStart, cStart});
                    temp[rStart][cStart] = true;
                    counter++;
                    dir = "right";
                    cStart++;
                }
            }
        }
        return result;
    }
};*/

int main(){
    Solution sol;
    vector<vector<int>> arr = sol.spiralMatrixIII(3, 3, 2, 0);
    return 0;
}