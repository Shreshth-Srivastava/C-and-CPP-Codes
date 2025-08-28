#include<iostream>
#include<bits/stdc++.h>
#include <string>
using namespace std;

// Hashmap Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> m;
        int count = 0;
        for(auto& domino:dominoes){
            if(domino[0] > domino[1]){
                swap(domino[0], domino[1]);
            }
            int key = domino[0]*10 + domino[1];
            count += m[key]++;
        }
        return count;
    }
};

// Brute Force Approach: Time Complexity -->O(N^2) ; Space Complexity --> O(1)

// class Solution {
// public:
//     int numEquivDominoPairs(vector<vector<int>>& dominoes) {
//         int n = dominoes.size(), count = 0;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if((dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1]) || 
//                 (dominoes[i][0] == dominoes[j][1] && dominoes[i][1] == dominoes[j][0])){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

int main(){
    Solution sol;
    // vector<vector<int>> dominoes = {{1,2},{2,1},{3,4},{5,6}};
    vector<vector<int>> dominoes = {{1,2},{1,2},{1,1},{1,2},{2,2}};
    cout<<sol.numEquivDominoPairs(dominoes);
    return 0;
}