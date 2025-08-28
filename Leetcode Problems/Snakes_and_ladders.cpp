#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N*2) ; Space Complexity --> O(N*2)

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int res = INT_MAX, n = board.size(), n2 = n*n;

        // unordered_map<int, int> myboard;
        int myboard[401] = {-1};
        vector<bool> visited(n2+1, false);

        int flow = false, sq = 0;
        for(int i=n-1;i>=0;--i){
            int j = 0, step = 1;
            
            if(flow){
                j = n-1;
                step = -1;
            }

            while(j>=0 && j<n){
                ++sq;
                // myboard.insert({sq, board[i][j]});
                myboard[sq] = board[i][j];

                j += step;
            }

            flow = flow ? false : true;
        }

        queue<pair<int, int>> q;    // {idx, currRes}

        q.push({1,0});
        visited[1] = true;
        while(!q.empty()){
            int currIdx = (q.front()).first, currRes = (q.front()).second;
            q.pop();

            if(myboard[currIdx] != -1){
                currIdx = myboard[currIdx];
            }

            if(currIdx == n2){
                res = min(res,currRes);
            }

            int start = currIdx+1, end = min(currIdx+6, n2);


            currRes++;

            if(end == n2){
                res = min(res,currRes);
            }

            for(start;start<=end;start++){
                if(!visited[start]){
                    q.push({start, currRes});
                    visited[start] = true;
                }
            }
        }

        return res != INT_MAX ? res : -1;
    }
};

int main(){
    Solution sol;
    // vector<vector<int>> board = {{1,1,-1},{-1,1,1},{-1,-1,1}};
    // vector<vector<int>> board = {{-1,-1},{-1,3}};
    // vector<vector<int>> board = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
    // vector<vector<int>> board = {{1,1,-1},{1,1,1},{-1,-1,1}};
    // vector<vector<int>> board = {{-1,-1,-1},{-1,-1,-1},{-1,-1,9}};
    vector<vector<int>> board = {{-1,-1,-1},{-1,9,8},{-1,8,9}};
    cout<<sol.snakesAndLadders(board);
    return 0;
}