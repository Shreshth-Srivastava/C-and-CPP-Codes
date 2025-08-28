#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

//Approach-1

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        
        for( int i = 0; i < points.size(); i++) {
            pair<int, int> entry = {squaredDistance(points[i]), i };
            if(pq.size() < k)
                pq.push(entry);
            else if(entry.first < pq.top().first) {
                pq.pop();
                pq.push(entry);
            }
        }

        vector<vector<int>> res;
        for(int i =0; i<k;i++) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }

    int squaredDistance(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};

// Approach-2
/*
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> triples;
        for (auto& p : points)
            triples.push_back({p[0] * p[0] + p[1] * p[1], p[0], p[1]});
        // Min heap of vectors (triples). This constructor takes O(n) time (n = len(v))
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(triples.begin(), triples.end());
        vector<vector<int>> res;
        while (k--){
            vector<int> el = pq.top();
            pq.pop();
            res.push_back({el[1], el[2]});
        }
        return res;
    }
};
*/

int main(){
    Solution sol;
    vector<vector<int>>points = {{-5,4},{-6,-5},{4,6}};
    vector<vector<int>> res = sol.kClosest(points, 2);
    for(int i=0;i<res.size();i++){
        cout<<"{"<<res[i][0]<<","<<res[i][1]<<"}";
    }
    return 0;
}