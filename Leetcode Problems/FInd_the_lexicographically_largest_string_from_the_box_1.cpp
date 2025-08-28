#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

// Editorial Solution - 2: Time Complexity --> O(N) ; Space Complexity --> O(N) for C++

class Solution {
public:
    string lastSubstring(string s) {
        int i = 0, j = 1, n = s.size();
        while (j < n) {
            int k = 0;
            while (j + k < n && s[i + k] == s[j + k]) {
                k++;
            }
            if (j + k < n && s[i + k] < s[j + k]) {
                int t = i;
                i = j;
                j = max(j + 1, t + k + 1);
            } else {
                j = j + k + 1;
            }
        }
        return s.substr(i, n - i);
    }

    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        string last = lastSubstring(word);
        int n = word.size(), m = last.size();
        return last.substr(0, min(m, n - numFriends + 1));
    }
};

// Editorial Solution - 1: Time Complexity --> O(N^2) ; Space Complexity --> O(N) for C++

// class Solution {
// public:
//     string answerString(string word, int numFriends) {
//         if (numFriends == 1) {
//             return word;
//         }
//         int n = word.size();
//         string res;
//         for (int i = 0; i < n; i++) {
//             res = max(res, word.substr(i, min(n - numFriends + 1, n - i)));
//         }
//         return res;
//     }
// };

// My Solution (Correct but TLE): 

// class Solution {
// public:
//     string answerString(string word, int numFriends) {
//         if(numFriends == 1) return word;
        
//         int windowMax = word.size() - numFriends + 1, n = word.size();
//         unordered_set<string> s;

//         int i = 0, j = 1;
//         while(j<=n){
//             if(j-i <= windowMax){
//                 s.insert(word.substr(i,j-i));
//             }
//             if(j-i == windowMax){
//                 helper(i, j, word, s);
//                 i++;
//             }
//             j++;
//         }

//         string res = *s.begin();

//         for(const auto& str:s){
//             res = max(res, str);
//         }
        
//         return res;
//     }

// private:
//     void helper(int i, int j, string& word, unordered_set<string>& s){
//         while(j-i > 0){
//             string temp = "";
//             temp += word[i];
//             s.insert(temp);
//             i++;
//             if(j-i>1){
//                 s.insert(word.substr(i,j-i));
//             }
//         }
//     }
// };

// My Solution - ALternate Version (MLE)

// class Solution {
// public:
//     string answerString(string word, int numFriends) {
//         if(numFriends == 1) return word;
        
//         int windowMax = word.size() - numFriends + 1, n = word.size();
//         vector<string> arr;

//         int i = 0, j = 1;
//         while(j<=n){
//             if(j-i <= windowMax){
//                 arr.push_back(word.substr(i,j-i));
//             }
//             if(j-i == windowMax){
//                 helper(i, j, word, arr);
//                 i++;
//             }
//             j++;
//         }

//         string res = arr[0];

//         for(const auto& s:arr){
//             res = max(res, s);
//         }
        
//         return res;
//     }
// private:
//     void helper(int i, int j, string& word, vector<string>& arr){
//         while(j-i > 0){
//             string temp = "";
//             // temp += word[i];
//             // temp.append(1, word[i]); Better way
//             arr.push_back(temp);
//             i++;
//             if(j-i>1){
//                 arr.push_back(word.substr(i,j-i));
//             }
//         }
//     }
// };

int main(){
    Solution sol;

    // string s = "bif";
    // cout<<sol.answerString(s, 2);

    // string s = "nbjnc";
    // cout<<sol.answerString(s, 2);

    // string s = "nnjnc";
    // cout<<sol.answerString(s, 2);

    string s = "vwmtvokuumoozyqnfhhrbecqvzbzzomlajpfogotetttjsishxfbwhkrhgyqgrpplojapenvxjypviaptwvenqxbvxjxjcsjjdeixysmdnrezqfddijhbmwlfsrkyamjnkhxxqfgwdmllekiuvnfczutdiyypesgrgqbfgrqoxvdtqbvdeduceigwdvmlhvzhtsfrjcwpghcgvtktpvwaarsrjgqbzsdxueztquxkolaypvzeakhvpysbdujvwcntlkpayjxujiiulvujlirfmuosapppbnfxpvtfneqwynnfwqkkzhgbaztjtmywzyajudejeigiiuepmbeichqojxbezphttnfyeobinrhmkepzhwonjgfrscctzwollvvvwbahgrjlhirixklrnkoprodyjpxsarevhqupawivwfiywqudsjkbxenbvhmnpzuoijxbxxfhifqnpgohruglwisttodnrotsiebaxtmjxcqvkijhebrsamsowbyglgeopovlydruwcrsmxmcohdnkjmuaectdjfjpeopgtalhiyymluqwfqncykyjjhkawdyandjeqaljaeaozqerhvfqugkdvrzmvdsmdakdgvynnzilxvqttoakbijtcatmeatptpwozhowjiqqschlupivcfbxzvnaeceirscrzwwanrpnneuijgrmzqullcnqkrywgtloczmjxcrkhpqiomnrfqbitzvhphqzscpdmrgwagozmbjirmbarfnhrtqyynbdnkkfvgcpizntwvpvkssiapelliftytzyqsrfswkkkhvalwptoppotsrljxykliagwvzlgshmqoptmtbmjhfciokiwvffltdghidlsvokkfiyzdwbktricbilmhbwwatlrdpsbgpnjdgafpblrqhxxsoheezsdcpxyqoyfpibxqfbegcopfaggwvcxyqkmzkcoxnyxnrpihapubhulugxaiqgirscajvfayxnil";
    cout<<sol.answerString(s, 475);
    return 0;
}