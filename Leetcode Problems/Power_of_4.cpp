#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Another Solution: Time Complexity --> O(1) ; Space Complexity --> O(1)

/*class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (log(n)/log(4)) == int(log(n)/log(4));
    }
};*/

// Bit-Mask Approach: Time Complexity --> O(1) ; Space Complexity --> O(1)

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0)
            return false;
        
        if((n & (n-1)) == 0){
            int mask = 1431655765;
            return ((mask | n) == mask);
        }

        return false;
    }
};
