#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
DSU(int n){
    parent.resize(n+1);
    rank.resize(n+1, 1);
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
}

bool unioncheck(int u, int v){
    int pu = find(u);
    int pv = find(v);

    if(pu == pv) return true;

    if (rank[pv] > rank[pu]) {
        swap(pu, pv);
    }
    parent[pv] = pu;
    rank[pu] += rank[pv];

    return false;
}

private:
vector<int> parent;
vector<int> rank;

int find(int node){
    int cur = node;
    while(cur != parent[cur]){
        parent[cur] = parent[parent[cur]];
        cur = parent[cur];
    }
    return cur;
}

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        DSU U(n);
        for(auto& e: edges){
            if(U.unioncheck(e[0], e[1])){
                return e;
            }
        }

        return {};
    }
};

int main(){
    Solution sol;
    // vector<vector<int>> edges = {{9,10},{5,8},{2,6},{1,5},{3,8},{4,9},{8,10},{4,10},{6,8},{7,9}};
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    sol.findRedundantConnection(edges);
}