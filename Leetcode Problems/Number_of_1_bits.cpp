#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0, temp;
        while(n > 0){
            temp = n % 2;
            n /= 2;
            if(temp == 1) count++;
        }
        return count;
    }
};

// Another Approach
// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         int bit = 0;
//         int result = 0;
        
//         while (n != 0) {
//             bit = n & 1;
//             if (bit == 1) {
//                 result++;
//             }
//             n = n >> 1;
//         }
        
//         return result;
//     }
// };