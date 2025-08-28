#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Bellman-Ford Method

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> res(n, 0);
        res[start] = 1;
        for(int i=0;i<n-1;i++){
            bool updated = false;
            for(int j = 0;j<edges.size();j++){
                int u = edges[j][0];
                int v = edges[j][1];
                double pathProb = succProb[j];
                if(res[u]*pathProb > res[v]){
                    res[v] = res[u]*pathProb;
                    updated = true;
                }
                if(res[u] < res[v]*pathProb){
                    res[u] = res[v]*pathProb;
                    updated = true;
                }
            }
            if(!updated) break;
        }
        return res[end];
    }
};


/*class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>adj[n]; //Creating adjacency list
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>>pq; //Use maxHeap for path with the maximum probability
        pq.push({1.0,start}); //{probability,node}
        vector<double>dist(n,INT_MIN);
        dist[start]=1;
        while(!pq.empty()){
            auto itr=pq.top();
            pq.pop();
            double dis=itr.first;
            int node=itr.second;
            for(auto it:adj[node]){
                int adjNode=it.first;
                double edW=it.second;
                if(dist[adjNode]<dis*edW){ //If greater probability is found then update probability of adjacent node & push adjacent node in maxHeap
                    dist[adjNode]=dis*edW;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }        
        if(dist[end]==INT_MIN) return 0.00000; //If there is no path from start to end
        else return dist[end];
    }
};*/

int main(){
    Solution sol;
    vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
    vector<double> prob = {0.5,0.5,0.2};
    cout<<sol.maxProbability(3, edges, prob, 0, 2);
    return 0;
}