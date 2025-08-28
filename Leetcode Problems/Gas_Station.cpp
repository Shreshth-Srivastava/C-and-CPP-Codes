#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Greedy Approach: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }

        int total = 0;
        int res = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += (gas[i] - cost[i]);

            if (total < 0) {
                total = 0;
                res = i + 1;
            }
        }

        return res;
    }
};

// Two Pointer Approach: Time Complexity --> O(N) ; Space Complexity --> O(1)

// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();
//         int start = n - 1, end = 0;
//         int tank = gas[start] - cost[start];
//         while (start > end) {
//             if (tank < 0) {
//                 start--;
//                 tank += gas[start] - cost[start];
//             } else {
//                 tank += gas[end] - cost[end];
//                 end++;
//             }
//         }
//         return tank >= 0 ? start : -1;
//     }
// };

// My Solution --> Time limit exceeded

// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();
//         for(int i=0;i<n;i++){
//             gas.push_back(gas[i]);
//             cost.push_back(cost[i]);
//         }
//         for(int i=0;i<n;i++){
//             // if(helper(i, n+i, 0, gas, cost)) return i;
//             if(cost[i] < gas[i]){
//                 int fuel = gas[i] - cost[i];
//                 for(int j=i+1;j<=n+i;j++){
//                     fuel += gas[j];
//                     if(fuel < cost[j]) break;
//                     fuel -= cost[j];
//                     if(j == n+i) return i;
//                 }
//             }
//         }
//         return -1;
//     }
// private:
//     bool helper(int start, int end, int fuel, vector<int>& gas, vector<int>& cost){
//         if(start == end) return true;
//         fuel += gas[start];
//         if(fuel < cost[start]) return false;
//         fuel -= cost[start];
//         return helper(start+1, end, fuel, gas, cost);
//     }
// };

int main(){
    Solution sol;
    // vector<int> gas = {2,3,4};
    // vector<int> cost = {3,4,3};
    // vector<int> gas = {5,1,2,3,4};
    // vector<int> cost = {4,4,1,5,1};
    vector<int> gas = {2};
    vector<int> cost = {2};
    cout<<sol.canCompleteCircuit(gas, cost);
}