#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(E + Q*(V+E)) or (N + Q) ; Space Complexity --> O(V+E) or (N + Q)
// E --> No. of Eqns ; Q --> No. of Queries ; V --> No. of unique Vars

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res(queries.size(), 0);
        unordered_map<string, vector<pair<string, double>>> m;
        
        for(int i=0;i<equations.size();++i){
            string node1 = equations[i][0], node2 = equations[i][1];
            double value1 = values[i], value2 = 1/values[i];

            m[node1].push_back({node2, value1});
            m[node2].push_back({node1, value2});
        }

        for(int i=0;i<queries.size();++i){
            string target = queries[i][1];
            if(m.find(target) != m.end() && m.find(queries[i][0]) != m.end() && queries[i][0] == target){
                res[i] = 1;
                continue;
            }

            res[i] = bfs(queries[i][0], target, m);
        }

        return res;
    }
private:
    double bfs(string node, string target, unordered_map<string, vector<pair<string, double>>>& m){
        queue<pair<string, double>> q;
        set<string> s;
        q.push({node, 1});
        s.insert(node);
            
        while(!q.empty()){
            pair<string, double> curr = q.front();
            q.pop();
            if(m.find(curr.first) != m.end()){
                for(const auto& val:m[curr.first]){
                    if(val.first == target){
                        return (curr.second * val.second);
                    }
                    else{
                        if(s.find(val.first) == s.end()){
                            q.push({val.first, (curr.second * val.second)});    
                            s.insert(val.first);
                        }
                    }
                }
            }
        }

        return -1.0;
    }
};

int main(){
    Solution sol;

    vector<vector<string>> eq = {{"a","b"},{"b","c"}};
    vector<double> val = {2.0,3.0};
    vector<vector<string>> q = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};

    sol.calcEquation(eq, val, q);

    return 0;
}