// Kahn's Algorithm is a popular method for performing topological sorting on a Directed Acyclic Graph (DAG). It begins by computing the in-degree (number of incoming edges) for each vertex. All nodes with in-degree zero are added to a queue, as they have no dependencies. The algorithm repeatedly removes a node from the queue, adds it to the topological order, and reduces the in-degree of its neighbors by one. If any neighbor’s in-degree becomes zero, it is added to the queue. This process continues until the queue is empty. If the topological ordering includes all vertices, the graph is acyclic, and the sort is successful. If not, a cycle exists, making topological sorting impossible. Kahn’s Algorithm ensures that every node is visited only once, making it efficient with a time complexity of O(V + E), where V is the number of vertices and E the number of edges. It is widely used in scenarios like scheduling tasks, resolving dependencies, and analyzing build systems. The algorithm is simple, intuitive, and well-suited for implementation using queues.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// LeetCode - 207
// NeetCode Kahn's Algorithm for Topological Sorting --> Time Complexity: O(V+E) ; Space Complexity: O(V+E)

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