#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Solution-1

class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> mp(26, 0);
        for (auto c : word) {
            mp[c-'a']++;
        }

        for (int i=0; i<word.size(); i++) {
            mp[word[i]-'a']--;
            if (isGood(mp)) return true;
            mp[word[i]-'a']++;
        }
        return false;
    }
private:
    bool isGood(vector<int> &mp) {
        int cnt = -1;
        for (int i : mp) {
            if (cnt == -1 && i != 0)
                cnt = i;
            if (i!=cnt && i!=0) 
                return false;
        }
        return true;
    }
};

// Solution-2

// class Solution {
// public:
//     bool equalFrequency(string word) {
//         vector<int> arr(26,0);
//         for(const auto& c:word) arr[c-'a']++;
        
//         for(int i=0;i<26;i++){
//             vector<int> temp=arr;
//             if(arr[i]==0) continue;
            
//             temp[i]--;
//             unordered_set<int> s;

//             for(const auto& x:temp){
//                 if(x>0){
//                     s.insert(x);
//                 }
//             }
//             if(s.size()==1){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

int main(){
    Solution sol;
    string word = "abcc";
    cout<<sol.equalFrequency(word);
    return 0;
}