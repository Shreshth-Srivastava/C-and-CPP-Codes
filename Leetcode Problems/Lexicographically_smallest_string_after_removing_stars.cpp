#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(NlogN) ; Space Complexity --> O(N)

struct CustomCompare {
    bool operator()(const pair<char, int>& a, const pair<char, int>& b) const {
        if (a.first != b.first)
            return a.first > b.first;  // lexicographically smaller char has higher priority
        return a.second < b.second;    // if same char, higher int has higher priority
    }
};

class Solution {
public:
    string clearStars(string& s) {
        int n = s.size();
        priority_queue<pair<char,int>, vector<pair<char,int>>, CustomCompare> pq;

        for(int i=0;i<n;++i){
            if(s[i] == '*'){
                pair<char, int> temp = pq.top();
                pq.pop();
                s[temp.second] = '{';
                s[i] = '{';
            }
            else{
                pq.push({s[i], i});
            }
        }

        string res = "";
        for(const auto& c:s){
            if(c != '{') res.append(1, c);
        }

        return res;
    }
};

// Without Custom Comparator Method

/*
class Solution {
public:
    string clearStars(string& s) {
        int n = s.size();
        priority_queue<pair<char,int>, vector<pair<char,int>>, greater<pair<char,int>>> pq;

        for(int i=0;i<n;++i){
            if(s[i] == '*'){
                pair<char, int> temp = pq.top();
                pq.pop();
                int idx = -1 * temp.second;
                s[idx] = '{';
                s[i] = '{';
            }
            else{
                pq.emplace(s[i], -i);
            }
        }

        string res = "";
        for(const auto& c:s){
            if(c != '{') res.append(1, c);
        }

        return res;
    }
};
*/

int main(){
    Solution sol;

    // string s = "aaba*b*";

    string s = "aaba*a*";

    cout<<sol.clearStars(s);

    return 0;
}