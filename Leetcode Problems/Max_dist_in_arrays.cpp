#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxDif = 0, curMin = 10000, curMax = -10000;
        for (auto& a : arrays) {
            maxDif = max(maxDif, max(a.back()-curMin, curMax-a.front()));
            curMin = min(curMin, a.front()), curMax = max(curMax, a.back());
        }
        return maxDif;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> arrays = {{1, 4},{0, 5}};
    cout<<sol.maxDistance(arrays);
    return 0;
}