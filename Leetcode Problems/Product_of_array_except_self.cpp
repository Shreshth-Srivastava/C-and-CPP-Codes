#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Solution-2 : Better Solution

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix = prefix * nums[i];
        }
        
        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] = result[i] * postfix;
            postfix = postfix * nums[i];
        }
        
        return result;
    }
};

// Solution-1

/*class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> postfix(n, 0);
        vector<int> prefix(n, 0);
        postfix[n-1] = nums[n-1];
        postfix[n-2] = nums[n-1];
        for(int i = n-3;i>=0;i--){
            postfix[i] = postfix[i+1]*nums[i+1];
        }
        prefix[0] = nums[0];
        prefix[1] = nums[0];
        for(int j = 2;j<n;j++){
            prefix[j] = prefix[j-1]*nums[j-1];
        }
        vector<int> answer(n, 0);
        answer[0] = postfix[0];
        answer[n-1] = prefix[n-1];
        for(int k=1;k<n-1;k++){
            answer[k] = prefix[k]*postfix[k];
        }
        return answer;
    }
};*/

int main(void){
    Solution sol;
    vector<int> nums = {1,2,3,4};
    vector<int> answer = sol.productExceptSelf(nums);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    return 0;
}