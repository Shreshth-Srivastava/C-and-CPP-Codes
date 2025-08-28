#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// NeetCode Kahn's Algorithm --> Time Complexity: O(V+E) ; Space Complexity: O(V+E)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        
        for (auto& pre : prerequisites) {
            indegree[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int finish = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            finish++;
            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return finish == numCourses;
    }
};

// NeetCode DFS Solution --> Time Complexity: O(V+E) ; Space Complexity: O(V+E)

/*class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<numCourses;i++) adjList[i] = {};
        for(const auto& pre: prerequisites){
            adjList[pre[0]].push_back(pre[1]);
        }
        for(int k=0;k<numCourses;k++){
            if(!dfs(k)) return false;
        }
        return true;
    }
private:
    unordered_map<int, vector<int>> adjList;
    unordered_set<int> visiting;

    bool dfs(int course){
        if(visiting.count(course)) return false;
        if(adjList[course].empty()) return true;

        visiting.insert(course);
        for (int pre : adjList[course]) {
            if (!dfs(pre)) {
                return false;
            }
        }
        visiting.erase(course);
        adjList[course].clear();
        return true;
    }
};*/