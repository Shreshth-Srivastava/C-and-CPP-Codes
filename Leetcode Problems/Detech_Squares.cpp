#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// HashMap - 1: Time Complexity --> O(1) for add() and O(N) for count() ; Space Complexity --> O(N)

// class CountSquares {
// private:
//     unordered_map<long, int> ptsCount;
//     vector<vector<int>> pts;

//     long getKey(int x, int y) {
//         return (static_cast<long>(x) << 32) | static_cast<long>(y);
//     }

// public:
//     CountSquares() {
//     }

//     void add(vector<int> point) {
//         long key = getKey(point[0], point[1]);
//         ptsCount[key]++; 
//         pts.push_back(point); 
//     }
    
//     int count(vector<int> point) {
//         int res = 0;
//         int px = point[0], py = point[1];

//         for (const auto& pt : pts) {
//             int x = pt[0], y = pt[1];
//             if (abs(py - y) != abs(px - x) || x == px || y == py) continue;
//             res += ptsCount[getKey(x, py)] * ptsCount[getKey(px, y)];
//         }
//         return res;
//     }
// };

// HaspMap-2: Time Complexity --> O(1) for add() and O(N) for count() ; Space Complexity --> O(N)

class DetectSquares {
public:
    DetectSquares() {}
    
    void add(vector<int> point) {
        ptsCount[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int x1 = point[0], y1 = point[1];

        for(auto& [y2, cnt]: ptsCount[x1]){
            int side = abs(y2 - y1);
            if(side == 0) continue;

            int x2 = x1+side, x3 = x1-side;
            res += cnt*ptsCount[x2][y1]*ptsCount[x2][y2];
            res += cnt*ptsCount[x3][y1]*ptsCount[x3][y2];
        }

        return res;
    }
private:
    unordered_map<int, unordered_map<int, int>> ptsCount;
};