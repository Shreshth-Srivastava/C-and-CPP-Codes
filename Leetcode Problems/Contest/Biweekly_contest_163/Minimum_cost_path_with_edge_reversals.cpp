#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Optimized Solution (Dijkstra's Algorithm) : Time Complexity --> O(V+E) ; Space Complexity --> O(V+E)

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }

        vector<int> dist(n, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u]) {
                continue;
            }

            if (u == n - 1) {
                return cost;
            }

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n-1] == INT_MAX ? -1 : dist[n-1];
    }
};

// My Solution (DFS) --> TLE : Time Complexity --> O(V*E) ; Space Complexity --> O(V+E) 
/*
Where V = Vertices and E = Edges; Additionally, using a map in this case (nodes from 0 to n-1) is inefficient.
*/

/*class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        map<int, vector<pair<int,int>>> m;
        vector<int> vals(n, INT_MAX);

        for(const auto& e: edges){
            m[e[0]].push_back({e[1], e[2]});
            m[e[1]].push_back({e[0], -1*e[2]});
        }

        stack<pair<int,int>> stk;
        stk.push({0,0});

        while(!stk.empty()){
            auto [node, val] = stk.top();
            stk.pop();

            if(val >= vals[node])
                continue;

            cout<<"Curr Node: "<<node<<", Val: "<<val<<endl;

            vals[node] = min(vals[node], val);

            for(const auto& child:m[node]){
                int weight = child.second < 0 ? abs(2*child.second) : child.second;
                int temp = val + weight;

                if(temp < vals[child.first]){
                    cout<<"To: "<<child.first<<", Weight: "<<weight<<endl;
                    stk.push({child.first, temp});
                }
            }
        }

        return vals[n-1] == INT_MAX ? -1 : vals[n-1];
    }
};
*/