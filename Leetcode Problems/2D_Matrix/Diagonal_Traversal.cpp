#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity --> O(N x M) ; Space Complexity --> O(N) for the result

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const int rows = mat.size(), cols = mat[0].size();
        int i = 0, j = 0;
        vector<int> res;

        bool upward = true;

        while(res.size() < rows*cols){
            res.push_back(mat[i][j]);

            if(upward){
                if(j == cols - 1){
                    i++;
                    upward = false;
                }else if(i == 0){
                    j++;
                    upward = false;
                }else{
                    i--; 
                    j++;
                }
            }else{
                if(i == rows - 1){
                    j++;
                    upward = true;
                }else if(j == 0){
                    i++;
                    upward = true;
                }else{
                    i++;
                    j--;
                }
            }
        }
        return res;
    }
};

// Time Complexity --> O(N x M) ; Space Complexity --> O(N x M)

/*class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const int rows = mat.size(), cols = mat[0].size();
        vector<int> res(rows*cols, 0);
        int resCnt = 0, i = 0, j = 0;
        map<int, vector<int>> m;

        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                m[i+j].push_back(mat[i][j]);
            }
        }

        bool dir = true;
        for(auto& [key, val]: m){
            for(int i = dir ? val.size()-1 : 0; dir ? i>=0 : i<val.size(); dir ? --i : ++i){
                cout<<val[i]<<endl;
                res[resCnt] = val[i];
                resCnt++;
            }
            dir = dir ? false : true;
        }

        return res;
    }
};*/