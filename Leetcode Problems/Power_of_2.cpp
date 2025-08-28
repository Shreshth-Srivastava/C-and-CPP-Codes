#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Solution: Time Complexity --> O(1) ; Space Complexity --> O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
      if (n <= 0) {
        return false;
      }

      return (n & (n - 1)) == 0;
    }
};

// My Solution: Time Complexity --> O(log(N)) ; Space Complexity --> O(1)
/*class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        
        while(n>0){
            if(n&1)
                cnt++;
            n = n >> 1;
        }
        
        return cnt == 1 ? true : false;
    }
};*/