#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution; Using Topological Sort, Time-Complexity--> O(V+E), Space Complexity--> O(V+E)

// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<int> res;
//         vector<int> temp(numCourses, 0);
//         int index = numCourses - 1;

//         vector<int> indegree(numCourses, 0);
//         vector<vector<int>> adj(numCourses);

//         for(auto& pre: prerequisites){
//             indegree[pre[1]]++;
//             adj[pre[0]].push_back(pre[1]);
//         }

//         queue<int> q;
//         for(int i=0; i<numCourses; ++i){
//             if(indegree[i]==0){
//                 q.push(i);
//                 temp[index] = i;
//                 index--;
//             }
//         }

//         int finish = 0;
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             finish++;
//             for(auto& nei: adj[node]){
//                 indegree[nei]--;
//                 if(indegree[nei] == 0){
//                     q.push(nei);
//                     temp[index] = nei;
//                     index--;
//                 }
//             }
//         }

//         if(finish == numCourses) res = temp;

//         temp.clear();
//         return res;
//     }
// };

// NeetCode Solution, Same approach but slightly cleaner code
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector<int> output(numCourses);
        while (!q.empty()) {
            int node = q.front();q.pop();
            output[numCourses - finish - 1] = node;
            finish++;
            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        if (finish != numCourses) {
            return {};
        }
        return output;
    }
};