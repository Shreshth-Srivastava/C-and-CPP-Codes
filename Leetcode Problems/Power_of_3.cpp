#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Approach: Time Complexity --> O(1) ; Space Complexity --> O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1)
            return false;
            
        return (1162261467 % n) == 0;
    }
};

// My Solution: Time Complexity --> O(1) ; Space Complexity --> O(1)

/*class Solution {
public:
    bool isPowerOfThree(int n) {
        int arr[20] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};
        
        for(const auto& num: arr){
            if(n == num)
                return true;
        }

        return false;
    }
};*/