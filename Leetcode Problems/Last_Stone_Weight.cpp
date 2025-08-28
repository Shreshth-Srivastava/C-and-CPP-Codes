#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    priority_queue<int> pq;
    int lastStoneWeight(vector<int>& stones) {
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size() > 1){
            int x,y;
            y = pq.top();
            pq.pop();
            x = pq.top();
            pq.pop();
            if(x != y) pq.push(y-x);
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};