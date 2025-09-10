#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(M x N) ; Space Complexity --> O(M x N)

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        const int rows = maze.size(), cols = maze[0].size();

        queue<pair<pair<int,int>,int>> q;
        q.push({{entrance[0],entrance[1]},0});
        maze[entrance[0]][entrance[1]] = 'E';

        while(!q.empty()){
            pair<pair<int,int>,int> curr = q.front();
            q.pop();

            int row = curr.first.first, col = curr.first.second, steps = curr.second;
            

            if(row == 0 || row == rows-1 || col == 0 || col == cols-1){
                if(maze[row][col] != 'E')
                    return steps;
            }

            if(row-1 >= 0 && maze[row-1][col] == '.'){
                q.push({{row-1,col},steps+1});
                maze[row-1][col] = '+';
            }
            if(row+1 <= rows-1 && maze[row+1][col] == '.'){
                q.push({{row+1,col},steps+1});
                maze[row+1][col] = '+';
            }
            if(col-1 >= 0 && maze[row][col-1] == '.'){
                q.push({{row,col-1},steps+1});
                maze[row][col-1] = '+';
            }
            if(col+1 <= cols-1 && maze[row][col+1] == '.'){
                q.push({{row,col+1},steps+1});
                maze[row][col+1] = '+';
            }
        }

        return -1;
    }
};