#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(rowIndex^2) ; Space Complexity --> O(rowIndex)

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row1(1, 1);
        for(int i=0;i<=rowIndex;i++){
            vector<int> row2(i+1,1);
            for(int j=1;j<i;j++){
                row2[j] = row1[j-1] + row1[j];
            }
            row1 = row2;
        }
        return row1;
    }
};

// Mathematical Approach: Time Complexity --> O(rowIndex) ; Space Complexity --> O(rowIndex)

// class Solution {
// public:
//     std::vector<int> getRow(int rowIndex) {
//         std::vector<int> res(1, 1);
//         long long prev = 1;
//         for(int k = 1; k <= rowIndex; k++) {
//             long long next_val = prev * (rowIndex - k + 1) / k;
//             res.push_back(next_val);
//             prev = next_val;
//         }
//         return res;
//     }
// };