#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
    string replace_words(string text) {
        size_t pos;
        while ((pos = text.find("Python")) != string::npos)
            text.replace(pos, 6, "#");
        while ((pos = text.find("Java")) != string::npos)
            text.replace(pos, 4, "Python");
        while ((pos = text.find("#")) != string::npos)
            text.replace(pos, 1, "Java");
        return text;
    }
};

int main(){
    Solution sol;
    string s = "Python and Java are object-oriented programming languages. JavaScript is not related to Java. Python is used for Django and Java is used for springboot.";
    cout<<sol.replace_words(s);
    return 0;
}