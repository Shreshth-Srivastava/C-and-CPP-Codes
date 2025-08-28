#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        pair<int,int> res = {INT_MAX, INT_MAX};
        int n = edges.size();

        vector<pair<int,int>> track(n, {-1, -1}); // track: (dist1, dist2)
        vector<bool> visited1(n, false);
        vector<bool> visited2(n, false);

        stack<int> stk;

        stk.push(node1);
        int dist1 = -1;
        
        while(!stk.empty()){
            int curr = stk.top();
            stk.pop();

            if(curr != -1 && !visited1[curr]){
                ++dist1;
                track[curr].first = dist1;
                stk.push(edges[curr]);
                visited1[curr] = true;
            }
        }

        stk.push(node2);
        int dist2 = -1;

        while(!stk.empty()){
            int curr = stk.top();
            stk.pop();

            if(curr != -1 && !visited2[curr]){
                ++dist2;
                track[curr].second = dist2;
                
                if(track[curr].first != -1){
                    int a = track[curr].first, b = track[curr].second;
                    int temp = max(a,b);
                    if(temp == res.second){
                        res.first = min(res.first, curr);
                    }
                    if(temp < res.second){
                        res.first = curr;
                        res.second = temp;
                    }
                }

                stk.push(edges[curr]);
                visited2[curr] = true;
            }
        }

        return res.first != INT_MAX ? res.first : -1;
    }
};

int main(){
    Solution sol;

    // vector<int>edges = {2,2,3,-1};
    // cout<<sol.closestMeetingNode(edges, 0, 1);

    // vector<int>edges = {1,0};
    // cout<<sol.closestMeetingNode(edges, 0, 1);

    vector<int>edges = {5,3,1,0,2,4,5};
    cout<<sol.closestMeetingNode(edges, 3, 2);

    return 0;
}