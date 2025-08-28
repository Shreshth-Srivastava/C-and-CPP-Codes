#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)

// class Solution {
// public:
//     bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
//         vector<int> track;
//         for(int i=0;i<triplets.size();i++){
//             if((triplets[i][0] <= target[0]) && (triplets[i][1] <= target[1]) && (triplets[i][2] <= target[2])){
//                 track.push_back(i);
//             }
//         }
//         int a = -1, b = -1, c = -1;
//         for(int i=0;i<track.size();i++){
//             int currIndex = track[i];
//             a = max(a, triplets[currIndex][0]);
//             b = max(b, triplets[currIndex][1]);
//             c = max(c, triplets[currIndex][2]);
//         }
//         if((a == target[0]) && (b == target[1]) && (c == target[2])){
//             return true;
//         }
//         return false;
//     }
// };

// My Solution using Set

// class Solution {
// public:
//     bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
//         unordered_set<int> track;
//         for(int i=0;i<triplets.size();i++){
//             if((triplets[i][0] <= target[0]) && (triplets[i][1] <= target[1]) && (triplets[i][2] <= target[2])){
//                 track.insert(i);
//             }
//         }
//         int a = -1, b = -1, c = -1;
//         for(const auto& element: track){
//             int currIndex = element;
//             a = max(a, triplets[currIndex][0]);
//             b = max(b, triplets[currIndex][1]);
//             c = max(c, triplets[currIndex][2]);
//         }
//         if((a == target[0]) && (b == target[1]) && (c == target[2])){
//             return true;
//         }
//         return false;
//     }
// };

// NeetCode Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

// class Solution {
// public:
//     bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
//         unordered_set<int> good;

//         for (const auto& t : triplets) {
//             if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) {
//                 continue;
//             }
//             for (int i = 0; i < t.size(); i++) {
//                 if (t[i] == target[i]) {
//                     good.insert(i);
//                 }
//             }
//         }
//         return good.size() == 3;
//     }
// };

// NeetCode Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x = false, y = false, z = false;
        for (const auto& t : triplets) {
            x |= (t[0] == target[0] && t[1] <= target[1] && t[2] <= target[2]);
            y |= (t[0] <= target[0] && t[1] == target[1] && t[2] <= target[2]);
            z |= (t[0] <= target[0] && t[1] <= target[1] && t[2] == target[2]);
            if (x && y && z) return true;
        }
        return false;
    }
};

int main(){
    Solution sol;
    // vector<vector<int>> triplets = {{2,5,3},{1,8,4},{1,7,5}};
    // vector<int> target = {2,7,5};
    vector<vector<int>> triplets = {{9,4,9},{7,4,8},{10,5,1},{3,7,6},{5,3,4}};
    vector<int> target = {9,7,9};
    cout<<sol.mergeTriplets(triplets, target);
    return 0;
}