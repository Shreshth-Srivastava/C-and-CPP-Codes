#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Neetcode Solution: Time Complexity --> O(N^2) ; Space Complexity --> O(N)

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), node = 0, edges = 0, res = 0;
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        while(edges < n-1){
            visited[node] = true;
            int nextNode = -1;
            for(int i=0;i<n;i++){
                if(visited[i]) continue;
                int curDist = calcDist(points[node][0], points[node][1], points[i][0], points[i][1]);
                dist[i] = min(dist[i], curDist);
                if(nextNode == -1 || dist[i] < dist[nextNode]){
                    nextNode = i;
                }
            }
            res += dist[nextNode];
            node = nextNode;
            edges++;
        }
        return res;
    }

private:
    int calcDist(int x1, int y1, int x2, int y2){
        int val = abs(x2 - x1) + abs(y2 - y1);
        return abs(val);
    }
};

int main(){
    Solution sol;
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    int res = sol.minCostConnectPoints(points);
    cout<<"Result: "<<res;
    return 0;
}