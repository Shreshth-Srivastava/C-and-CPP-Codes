#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(NlogN) ; Space Complexity --> O(logN) for sorting in C++

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        for(int i=0;i<n-1;++i){
            if(arr[i] > 0){
                if(binarySearch(i+1, n-1, arr, arr[i]*2)){
                    return true;
                }
            }
            else{
                if(!(arr[i]&1) && binarySearch(i+1, n-1, arr, arr[i]/2)){
                    return true;
                }
            }
        }

        return false;
    }
private:
    bool binarySearch(int idx, int n, vector<int>& arr, int target){
        int low = idx, high = n, mid;
        while(low <= high){
            mid = low + (high-low)/2;
            if(arr[mid] == target) return true;
            if(arr[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;

    // vector<int> nums = {-10,12,-20,-8,15};
    // vector<int> nums = {0,-2,2};
    vector<int> nums = {102,-592,457,802,98,-132,883,356,-857,461,-453,522,250,476,991,540,-852,-485,-637,999,-803,-691,-880,881,-584,750,-124,745,-909,-892,304,-814,868,665,50,-40,26,-242,-797,-360,-918,-741,88,-933,-93,360,-738,833,-191,563,449,840,806,-87,-950,508,74,-448,-815,-488,639,-334};

    cout<<sol.checkIfExist(nums);

    return 0;
}