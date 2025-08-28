#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)

class Solution {
public:
    string convert(string& s, int numRows) {
        if(numRows >= s.size() || numRows == 1) return s;

        int n = s.size();
        string res = "";
        
        vector<string> arr(numRows, "");

        int step = 1, currRow = 0;
        for(int i=0;i<n;++i){
            arr[currRow].append(1,s[i]);
            if(currRow == numRows-1) step = -1;
            if(currRow == 0) step = 1;
            currRow += step;
        }

        res.append(arr[0]);

        for(int i=1;i<numRows;++i){
            res.append(arr[i]);
        }

        return res;
    }
};

int main(){
    Solution sol;

    // string s = "ABCDEF";

    string s = "PAYPALISHIRING";

    cout<<sol.convert(s, 3);

    return 0;
}