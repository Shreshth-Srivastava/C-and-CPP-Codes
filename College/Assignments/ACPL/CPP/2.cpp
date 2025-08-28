#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int BinarySearch(vector<int>& arr, int target){
        int start = 0, end = arr.size() - 1, mid;
        while (start<=end)
        {
            mid = start + (end-start) / 2;
            if(arr[mid] == target) return mid;
            else{
                if(arr[mid] > target) end = mid-1;
                else start = mid + 1;
            }
        }
        
        return -1;
    }
};


int main(){
    Solution sol;
    vector<int> arr = {11, 20, 25, 37};
    cout<<sol.BinarySearch(arr, 11);
    return 0;
}