#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)
/*class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i = 0, k = 0, n = s.size();
        while (i < n) {
            // Find the starting pos of the next word
            while (i < n && s[i] == ' ') i++;

            if (i != n && k > 0) { // Still have the next word, add " " here
                s[k++] = ' ';
            }

            int start_index = k;
            // Find the ending pos of that word
            while (i < n && s[i] != ' ') s[k++] = s[i++];

            // Reverse that word
            reverse(s.begin() + start_index, s.begin() + k);
        }
        s.resize(k);
        return s;
    }
};*/

// Another Approach
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans;
        int i=n-1;
        while(i>=0 && s[i]==' ')  i--;
        while(i>=0)
        {
            if(s[i]==' ')
            {
                ans.push_back(' ');
                while(i>=0 && s[i]==' ')  i--;
            }
            int start=ans.size();
            while(i>=0 && s[i]!=' ')  ans.push_back(s[i--]);
            reverse(ans.begin()+start, ans.end());
            
        }
        if(ans.back()==' ')  ans.pop_back();
        return ans;
    }
};

// My Solution: Time Complexity --> O(N^2) ; Space Complexity --> O(N)

/*class Solution {
public:
    string reverseWords(string& s) {
        stringstream stream(s);
        string word, res = "";

        while(getline(stream, word, ' ')){
            if(word != "")
                res = " " + word + res;
        }

        res.erase(0, 1);

        return res;
    }
};*/

int main(){
    Solution sol;

    cout<<sol.reverseWords("This World is Beautiful  ");

    return 0;
}