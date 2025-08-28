#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Hash Map Approach: Time Complexity --> O(N) ; Space Complexity --> O(N)

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> count;
        for (int num : hand) count[num]++;
        
        for (int num : hand) {
            int start = num;
            while (count[start - 1] > 0) start--;
            while (start <= num) {
                while (count[start] > 0) {
                    for (int i = start; i < start + groupSize; i++) {
                        if (count[i] == 0) return false;
                        count[i]--;
                    }
                }
                start++;
            }
        }
        return true;
    }
};

// Sorting Approach: Time Complexity --> O(NlogN) ; Space Complexity --> O(N)

// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {
//         if (hand.size() % groupSize != 0) return false;

//         sort(hand.begin(), hand.end());
//         unordered_map<int, int> m;

//         for(int val: hand) m[val]++;
//         for(int num: hand){
//             if (m[num] > 0) {
//                 for (int i = num; i < num + groupSize; i++) {
//                     if (m[i] == 0) return false;
//                     m[i]--;
//                 }
//             }
//         }
//         return true;
//     }
// };