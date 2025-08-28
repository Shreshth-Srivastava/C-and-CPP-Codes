#include <fstream>
#include <map>
#include <sstream>
using namespace std;

class Solution{
public:
    void word_count_file(string in_file, string out_file) {
        ifstream in(in_file);
        ofstream out(out_file);
        map<string, int> count;
        string word;
        while (in >> word) count[word]++;
        for (auto& p : count)
            out << p.first << ": " << p.second << endl;
    }
};

int main(){
    Solution sol;
    string in_file = R"(./8_Input_file.txt)";
    string out_file = R"(./8_Output_file.txt)";
    sol.word_count_file(in_file, out_file);
    return 0;
}