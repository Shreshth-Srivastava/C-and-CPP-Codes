#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        int A[10]={0};
        
        for(auto &x:digits) A[x]++;
        
        for(int i=100;i<999;i+=2)
        {
            int d1=i/100,d2=i/10%10,d3=i%10;
            if(--A[d1]>=0 & --A[d2]>=0 & --A[d3]>=0) ans.push_back(i);
            A[d1]++,A[d2]++,A[d3]++;                                   
        }
        
        return ans;
    }
};

// Simpler Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

// class Solution {
//  public:
//   vector<int> findEvenNumbers(vector<int>& digits) {
//     // generating frequency map of the given digits
//     vector<int> count(10, 0);
//     for (auto& d : digits) count[d]++;

//     vector<int> res;

//     for (int num = 100; num < 999; num += 2) {
//       // generating frequency map of the current number
//       vector<int> currCount(10, 0);
//       int temp = num;

//       while (temp) {
//         currCount[temp % 10]++;
//         temp /= 10;
//       }

//       // checking if the number can be generated or not
//       bool flag = true;
//       for (int i = 0; i < 10; i++) {
//         if (currCount[i] > count[i]) {
//           flag = false;
//           break;
//         }
//       }

//       if (flag) {
//         res.push_back(num);
//       }
//     }
//     return res;
//   }
// };

int main(){
    Solution sol;
    vector<int> digits = {2,1,3,0};
    sol.findEvenNumbers(digits);
    return 0;
}