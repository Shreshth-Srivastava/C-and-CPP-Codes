#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Suffix Approach (LLM): Time Complexity --> O(N) ; Space Complexity --> O(N)
class Solution {
public:
    string robotWithString(string& s) {
        int n = s.size();
        if (n == 0) {
            return "";
        }

        // Calculate the minimum character suffix for each position
        // minCharSuffix[i] stores the smallest character from s[i] to s[n-1]
        std::vector<char> minCharSuffix(n);
        minCharSuffix[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            minCharSuffix[i] = std::min(s[i], minCharSuffix[i + 1]);
        }

        std::stack<char> stk;
        std::string res = "";

        for (int i = 0; i < n; ++i) {
            // Push the current character onto the stack
            stk.push(s[i]);

            // While the stack is not empty and the top of the stack
            // is less than or equal to the minimum character in the remaining suffix
            // (meaning we can potentially append it to the result string now)
            while (!stk.empty() && (i == n - 1 || stk.top() <= minCharSuffix[i + 1])) {
                res.push_back(stk.top());
                stk.pop();
            }
        }

        // Append any remaining characters in the stack to the result in reverse order
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }

        return res;
    }
};

// Better Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)

// class Solution {
// public:
    
//     char low(vector<int> & freq){    // this function return the smallest char present
        
//         for(int i=0;i<26;i++){
//             if(freq[i]!=0)return 'a'+i;
//         } 
//         return 'a';   
//     }
    
//     string robotWithString(string s) {
        
//         stack<char> t;
//         string ans="";  
//         vector<int> freq(26,0);
//         for(char c:s){
//             freq[c-'a']++;
//         }
        
//         //  *********** main logic 
//         for(char c:s){
//             t.push(c);
//              freq[c-'a']--; 
//             while(t.size()>0 && t.top()<=low(freq)){
//                 char x = t.top(); 
//                 ans+= x;
//                 t.pop();  
//             }    
//         }
        
//          while(t.size()>0){
//              ans+= t.top();
//              t.pop();   
//         }
//       //**********************
//         return ans;
      
//     }
// };

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)

// class Solution {
// public:
//     string robotWithString(string& s) {
//         int n = s.size(), idx=0;
//         stack<char> stk;
//         string res = "";

//         vector<queue<int>> arr(26);

//         for(int i=0;i<n;++i){
//             arr[s[i] - 'a'].push(i);
//         }

//         for(int i=0;i<26;++i){
//             while(!arr[i].empty()){
//                 int temp = arr[i].front();
//                 arr[i].pop();

//                 while(idx<=temp){
//                     stk.push(s[idx]);
//                     idx++;
//                 }

//                 while(!stk.empty() && (stk.top() - 'a') <= i){
//                     res.append(1, stk.top());
//                     stk.pop();
//                 }
//             }
//         }

//         return res;
//     }
// };

int main(){
    Solution sol;

    // string s = "nbjna";

    // string s = "nbjnb";

    // string s = "mmuqezwmomeplrtskz";

    string s = "vzhofnpo";

    cout<<sol.robotWithString(s);

    return 0;
}