// Better Solution

class Solution {
public:
    bool isPalindrome(string s) {
       int start=0;
       int end=s.size()-1;
       while(start<=end){
           if(!isalnum(s[start])){start++; continue;}
           if(!isalnum(s[end])){end--;continue;}
           if(tolower(s[start])!=tolower(s[end]))return false;
           else{
               start++;
               end--;
           }
       }
       return true;
}
};

// My Solution
/*
class Solution {
public:
    void helper(string& s){
        int i=0;
        while(i<s.size()){
            if(isupper(s[i])) s[i] = s[i] + 32;
            else if(s[i] == ' '){
                s.erase(s.begin()+i);
                continue;
            }
            else if(!isalnum(s[i])){
                s.erase(s.begin()+i);
                continue;
            }
            i++;
        }
    }

    bool isPalindrome(string s) {
        helper(s);
        int ptr1 = 0, ptr2 = s.size()-1;
        while(ptr1<ptr2){
            if(s[ptr1] != s[ptr2]) return false;
            ptr1++;
            ptr2--;
        }
        return true;
    }
};
*/