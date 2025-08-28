#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Solution

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for (string& s: arr) mp[s]++;
        for (string& s: arr) {
            if (mp[s] == 1) {
                k--;
                if (k == 0) return s;
            }
        }
        return "";
    }
};

// My Solution

/*class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> s;
        int n = arr.size();
        for(int i=0;i<n;i++){
            auto flag = find(arr.begin()+i+1, arr.end(), arr[i]);
            if(flag == arr.end() && !s.count(arr[i])){
                k--;
                if(k == 0) return arr[i];
            }
            s.insert(arr[i]);
        }
        return "";
    }
};*/

int main(){
    Solution sol;
    vector<string> arr = {"d","b","c","b","c","a"};
    sol.kthDistinct(arr, 2);
    return 0;
}