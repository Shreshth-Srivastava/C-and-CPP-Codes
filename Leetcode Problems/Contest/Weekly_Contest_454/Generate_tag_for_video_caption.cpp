#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<cctype>
using namespace std;

class Solution {
public:
    string generateTag(string& caption) {
        int idx = 0;
        while(caption[idx] == ' '){
            caption.erase(idx, 1);
            idx++;
        }

        stringstream s(caption);
        string word;
        string res = "#";

        getline(s, word, ' ');
        lowercase(word);
        if((int)word[0] < 97){
            word[0] = (int)word[0] + 32;
        }
        res.append(word);
        while(getline(s, word, ' ')){
            lowercase(word);
            if((int)word[0] >= 97){
                word[0] = (int)word[0] - 32;
            }
            res.append(word);
        }
        // cout<<res.size()<<endl;

        if(res.size() > 100){
            res = res.substr(0, 100);
        }
        // cout<<res.size()<<endl;

        return res;
    }
private:
    void lowercase(string& word){
        for(int i=0;i<word.size();){
            if((int)word[i] < 65 || (int)word[i] > 122){
                word.erase(i, 1);
            }
            else{
                if((int)word[i] < 97){
                    word[i] = (int)word[i] + 32;
                }
                i++;
            }
        }
    }
};

int main(){
    Solution sol;

    string caption = "Leetcode daily streak achieved";
    // string caption = "can I Go There";
    // string caption = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh";
    // string caption = "Leetcode dAily streak achieved";
    // string caption = " fPysaRtLQLiMKVvRhMkkDLNedQKffPnCjbITBTOVhoVjiKbfSawvpisDaNzXJctQkn";

    cout<<sol.generateTag(caption);

    return 0;
}