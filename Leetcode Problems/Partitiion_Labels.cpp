#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N^3) ; Space Complexity -->O(1)

// class Solution {
// public:
//     vector<int> partitionLabels(string& s) {
//         vector<int> res;
//         int index = 0;
//         while(index < s.size()){
//             char currElem = s[index];
//             int lastIndex = index;

//             // for(int i=index+1;i<s.size();i++){
//             //     if(s[i] == currElem){
//             //         lastIndex = i;
//             //     }
//             // }

//             lastIndex = max(lastIndex, helper(index+1, currElem, lastIndex, s));


//             for(int j = index+1;j<=lastIndex;j++){
//                 int temp = j;
//                 char tempElem = s[j];
//                 // for(int k=j+1;j<s.size();j++){
//                 //     if(s[k] == tempElem){
//                 //         temp = k;
//                 //     }
//                 // }

//                 temp = max(temp, helper(j+1, tempElem, temp, s));
                
//                 lastIndex = max(lastIndex, temp);
//             }

//             res.push_back(lastIndex + 1 - index);
//             index = lastIndex+1;
//         }

//         return res;
//     }

// private:
//     int helper(int index, char currElem, int& lastIndex, string& s){
//         for(int i=index;i<s.size();i++){
//             if(s[i] == currElem){
//                 lastIndex = i;
//             }
//         }
//         return lastIndex;
//     }
// };

// NeetCode Solution: Time Complexity --> O(N) ; Space Complexity --> O(M) ; where N is the size of s and M is the number of unique characters in s

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex;
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i]] = i;
        }

        vector<int> res;
        int size = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            size++;
            end = max(end, lastIndex[s[i]]);

            if (i == end) {
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    // string s = "ababcbacadefegdehijhklij";
    // string s = "qvmwtmzzse";
    string s = "eccbbbbdec";
    vector<int> arr = sol.partitionLabels(s);
    for(int element: arr){
        cout<<element<<"\t";
    }
    return 0;
}