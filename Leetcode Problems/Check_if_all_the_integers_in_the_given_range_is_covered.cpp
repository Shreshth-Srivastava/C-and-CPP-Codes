#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Difference Array Approach: Time Complexity --> O(N+M) where M is the number of ranges ; Space Complexity --> O(N)

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> arr(52, 0);

        for(const auto& elem: ranges){
            arr[elem[0]] += 1;
            arr[elem[1] + 1] -= 1;
        }

        for(int i=1, overlaps=0;i<=right;++i){
            overlaps += arr[i];
            if(i >= left && overlaps == 0){
                return false;
            }
        }

        return true;
    }
};

// My Solution: Time Complexity --> O(N^2) ; Space Complexity --> O(N)

/*class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<bool> arr(right+1, false);

        for(const auto& elem: ranges){
            for(int i=elem[0];i<=elem[1];++i){
                if(!arr[i]){
                    arr[i] = true;
                }
            }
        }

        for(left;left<=right;++left){
            if(!arr[left]){
                return false;
            }
        }

        return true;
    }
};*/