#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        int cur = node;
        while (cur != parent[cur]) {
            parent[cur] = parent[parent[cur]];
            cur = parent[cur];
        }
        return cur;
    }

    bool unionSets(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) {
            return false;
        }
        if (rank[pv] > rank[pu]) {
            swap(pu, pv);
        }
        parent[pv] = pu;
        rank[pu] += rank[pv];
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int res = n;
        for (auto& edge : edges) {
            if (dsu.unionSets(edge[0], edge[1])) {
                res--;
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    int n = 7;
    vector<vector<int>> edges = {{0,1}, {1,2}, {6,5}, {6,4}, {4,5}, {0,3}, {2,3}, {3,4}};
    int res = sol.countComponents(n, edges);
    cout<<"\nResult: "<<res;
    return 0;
}