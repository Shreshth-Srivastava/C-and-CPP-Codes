#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        if(n == 0) return true;
        if(nums.size() == 1){
            if(nums[0] == 0) return true;
            else return false;
        }

        int l = -1, r = 1;

        for(int i=0;i<nums.size();++i,++l,++r){
            if(nums[i] != 0) continue;
            
            int left = l>=0?nums[l]:0;
            int right = r<nums.size()?nums[r]:0;

            if(left == 0 && right == 0){
                nums[i] = 1;
                n--;
            }

            if(n == 0) return true;
        }

        return false;
    }
};

int main(){
    Solution sol;

    // vector<int> nums = {0,0,1,0,1};
    vector<int> nums = {1,0,0,0,1};
    cout<<sol.canPlaceFlowers(nums, 1);

    // vector<pair<pair<vector<int>, int>, bool>> tests;

    // vector<int> nums = {1,0,0,0,1};
    // int n = 1;

    // tests.push_back({{nums, n}, true});

    // nums = {1,0,0,0,1};
    // n = 2;

    // tests.push_back({{nums, n}, false});

    // nums = {1};
    // n = 1;

    // tests.push_back({{nums, n}, false});

    // nums = {0};
    // n = 1;

    // tests.push_back({{nums, n}, true});

    // nums = {0};
    // n = 0;

    // tests.push_back({{nums, n}, true});

    // nums = {1,0};
    // n = 1;

    // tests.push_back({{nums, n}, false});

    // nums = {0,1};
    // n = 1;

    // tests.push_back({{nums, n}, false});

    // nums = {0,1,0};
    // n = 1;

    // tests.push_back({{nums, n}, false});

    // nums = {0,0,1,0,1};
    // n = 1;

    // tests.push_back({{nums, n}, false});

    // int counter = 0;

    // for(auto& test: tests){
    //     vector<int>& nums = (test.first).first;
    //     int& n = (test.first).second;
    //     bool result = sol.canPlaceFlowers(nums, n);
    //     bool correctOp = test.second;
    //     cout<<"Test-"<<counter<<endl;
    //     if(result == correctOp) cout<<"Correct"<<endl;
    //     else cout<<"Incorrect"<<endl;
    //     counter++;
    // }
    
    return 0;
}