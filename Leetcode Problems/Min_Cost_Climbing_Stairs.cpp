#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minCostClimbingStairs(vector<int>& cost){
        cost.push_back(0);
        for(int i = cost.size()-3;i>=0;i--){
            cost[i] += min(cost[i+1],cost[i+2]);
        }
        return min(cost[0],cost[1]);
    }
};

// Another Method

// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int downOne = 0;
//         int downTwo = 0;
//         for (int i = 2; i <= cost.size(); i++) {
//             int temp = downOne;
//             downOne = min(downOne + cost[i - 1], downTwo + cost[i - 2]);
//             downTwo = temp;
//         }
        
//         return downOne;
//     }
// };