#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Space Complexity

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            //                 i / 2      i % 2
            result[i] = result[i >> 1] + (i & 1);
        }
        
        return result;
    }
};

// My Solution

// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> arr;
//         for(int i=0;i<=n;i++){
//             arr.push_back(hammingWeight(i));
//         }
//         return arr;
//     }

//     int hammingWeight(int n) {
//         unsigned int count = 0, temp;
//         while(n > 0){
//             temp = n % 2;
//             n /= 2;
//             if(temp == 1) count++;
//         }
//         return count;
//     }
// };