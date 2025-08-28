#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N^2) ; Space Complexity --> O(N^2)

class DSU{
private:
    vector<int> parent, size;
public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);

        for(int i=0;i<=n;++i){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int n){
        if(parent[n] != n){
            parent[n] = find(parent[n]);
        }

        return parent[n];
    }

    bool unionBySize(int u, int v){
        int pu = find(u), pv = find(v);

        if(pu == pv)
            return false;

        if(size[pu] > size[pv]){
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        else{
            size[pv] += size[pu];
            parent[pu] = pv;
        }

        return true;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), provinces = n;

        DSU dsu(n);

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(isConnected[i][j] == 1){
                    if(dsu.unionBySize(i, j))
                        provinces--;
                }
            }
        }

        return provinces;
    }
};