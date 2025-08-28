#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int res = 0;
        vector<bool> arr(n, false);
        arr[0] = true;

        vector<vector<int>> m(n);
        for(const auto& val: connections){
            m[val[0]].push_back(-1*val[1]);
            m[val[1]].push_back(val[0]);
        }

        stack<int> stk;
        stk.push(0);

        while(!stk.empty()){
            int curr = stk.top();
            stk.pop();
            for(const auto& elem: m[curr]){
                if(!arr[abs(elem)]){
                    if(elem < 0) res++;
                    arr[abs(elem)] = true;
                    stk.push(abs(elem));
                }
            }
        }

        return res;
    }
};

int main(){
    Solution sol;

    // vector<vector<int>> nums = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    // cout<<sol.minReorder(6, nums);

    // vector<vector<int>> nums = {{1,0},{1,2},{3,2},{3,4}};
    // cout<<sol.minReorder(5, nums);

    vector<vector<int>> nums = {{0,2},{0,3},{4,1},{4,5},{5,0}};
    cout<<sol.minReorder(6, nums);

    return 0;
}