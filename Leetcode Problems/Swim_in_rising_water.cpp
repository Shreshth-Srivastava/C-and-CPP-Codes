#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Different Approach: Time Complexity --> O((N^2)logN) ; Space Complexity --> O(N^2)

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        while (!pq.empty()) {
            auto [time, pos] = pq.top(); pq.pop();
            int x = pos.first, y = pos.second;

            if (x == n - 1 && y == n - 1) return time;

            for (auto& d : dir) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    pq.push({max(time, grid[nx][ny]), {nx, ny}});
                }
            }
        }
        return -1;
    }
};

// NeetCode Solution (Dijkstra's Algorithm via MinHeap): Time Complexity --> O((N^2)logN) ; Space Complexity --> O(N^2)

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        set<pair<int, int>> visit;
        priority_queue<vector<int>, 
                       vector<vector<int>>, greater<>> minHeap;
        vector<vector<int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        minHeap.push({grid[0][0], 0, 0});
        visit.insert({0, 0});

        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            int t = curr[0], r = curr[1], c = curr[2];
            if (r == N - 1 && c == N - 1) {
                return t;
            }
            for (const auto& dir : directions) {
                int neiR = r + dir[0], neiC = c + dir[1];
                if (neiR < 0 || neiC < 0 || neiR == N || 
                    neiC == N || visit.count({neiR, neiC})) {
                    continue;
                }
                visit.insert({neiR, neiC});
                minHeap.push({
                    max(t, grid[neiR][neiC]), neiR, neiC
                });
            }
        }

        return N * N;
    }
};