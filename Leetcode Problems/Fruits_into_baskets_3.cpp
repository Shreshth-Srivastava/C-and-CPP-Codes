#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast","unroll-loops","-ffast-math","march=native")

// Time Complexity --> O(NlogN) ; Space Complexity --> O(N)

class Solution {
    vector<int> segTree;

private:
    void buildSegTree(vector<int>& baskets, int s, int e, int st_idx){
        if(s == e){
            segTree[st_idx] = baskets[s];
            return;
        }

        int m = s + (e-s)/2;

        buildSegTree(baskets, s, m, 2*st_idx);
        buildSegTree(baskets, m+1, e, 2*st_idx+1);

        segTree[st_idx] = max(segTree[2*st_idx], segTree[2*st_idx+1]);
    }

    int findLeftMost(const int& fruit, int s, int e, int st_idx){
        if(segTree[st_idx] < fruit)
            return -1;
        
        if(s == e){
            segTree[st_idx] = -1;
            return 1;
        }

        int m = s + (e-s)/2;
        int val = segTree[2*st_idx] >= fruit ? 
        findLeftMost(fruit, s, m, 2*st_idx) : findLeftMost(fruit, m+1, e, 2*st_idx+1);
        
        segTree[st_idx] = max(segTree[2*st_idx], segTree[2*st_idx+1]);
        return val;
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        segTree.resize(4*n);

        int st_idx = 1;
        buildSegTree(baskets, 0, n-1, st_idx);

        int res = 0;

        for(int i=0;i<n;++i){
            if(findLeftMost(fruits[i], 0, n-1, st_idx) == -1)
                res++;
        }
        
        return res;
    }
};