#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(101, 0);

        for(const auto& num: nums){
            arr[num]++;
        }

        for(const auto& elem: arr){
            if(elem == 0)
                continue;

            if(checkPrime(elem))
                return true;
        }

        return false;
    }
private:
    bool checkPrime(int num){
        if(num == 1) return false;
        for(int i=2;i<num;++i){
            if(num%i == 0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {1,2,3,4,5};

    cout<<sol.checkPrimeFrequency(nums);

    return 0;
}