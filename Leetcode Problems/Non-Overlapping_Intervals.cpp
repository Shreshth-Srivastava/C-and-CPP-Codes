#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Sorting by end: Time Complexity --> O(NlogN) ; Space Complexity --> O(1)

// class Solution {
// public:
//     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//         sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
//             return a[1] < b[1];
//         });
//         int res = 0;
//         int prevEnd = intervals[0][1];

//         for (int i = 1; i < intervals.size(); i++) {
//             int start = intervals[i][0];
//             int end = intervals[i][1];
//             if (start < prevEnd) {
//                 res++;
//             } else {
//                 prevEnd = end;
//             }
//         }
//         return res;
//     }
// };

// Sorting by start: Time Complexity --> O(NlogN) ; Space Complexity --> O(1)

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1], res = 0;

        for(int i=1;i<intervals.size();i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start >= prevEnd){
                prevEnd = end;
            }
            else{
                res++;
                prevEnd = min(end, prevEnd);
            }
        }

        return res;
    }
};