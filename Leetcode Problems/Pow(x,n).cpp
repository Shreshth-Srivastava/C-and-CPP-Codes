#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Binary Exponentiation (Iterative): Time Complexity --> O(logN) ; Space Complexity --> O(1)

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;

        double res = 1;
        long power = abs((long)n);

        while (power) {
            if (power & 1) {
                res *= x;
            }
            x *= x;
            power >>= 1;
        }

        return n >= 0 ? res : 1 / res;
    }
};

// Binary Exponentiation (Recursive): Time Complexity --> O(logN) ; Space Complexity --> O(logN) for recursion stack

// class Solution {
// public:
//     double myPow(double x, int n) {
//         if (x == 0) {
//             return 0;
//         }
//         if (n == 0) {
//             return 1;
//         }

//         double res = helper(x, abs(static_cast<long>(n)));
//         return (n >= 0) ? res : 1 / res;
//     }

// private:
//     double helper(double x, long n) {
//         if (n == 0) {
//             return 1;
//         }
//         double half = helper(x, n / 2);
//         return (n % 2 == 0) ? half * half : x * half * half;
//     }
// };

// My Solution

// class Solution {
// public:
//     double myPow(double x, int n) {
//         double res = 1;
//         while(n>0){
//             res *= x;
//             n--;
//         }
//         while(n<0){
//             res /= x;
//             n++;
//         }
//         return res;
//     }
// };