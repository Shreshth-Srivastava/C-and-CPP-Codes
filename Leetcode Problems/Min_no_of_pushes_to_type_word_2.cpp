#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> arr(26, 0);
        int n = word.size(), factor = 1, result = 0;
        for(int i=0;i<n;i++){
            arr[word[i] - 'a']++;
        }
        sort(arr.begin(), arr.end(), greater<int>());
        for(int j=0;j<26;j++){
            if(arr[j] != 0){
                factor = j/8+1;
                result += factor*arr[j];
            }
            else break;
        }
        return result;
    }
};

int main(){
    Solution sol;
    string str = "xyzxyzxyzxyz";
    cout<<sol.minimumPushes(str);
    return 0;
}