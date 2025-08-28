#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// 1

/*class TrieNode{
public:
    TrieNode* children[2] = {NULL, NULL};
    bool isTerminal = false;
};

class Trie{
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode* node = root;
        int curr = 0;
        
        for(int i=0;i<word.size();i++){
            curr = word[i] - '0';
            if(node->children[curr] == NULL) node->children[curr] = new TrieNode();
            node = node->children[curr];
        }

        node->isTerminal = true;
    }
    bool search(string word){
        TrieNode* node = root;
        int curr = 0;

        for(int i=0;i<word.size();i++){
            curr = word[i] - '0';
            if(node->children[curr] == NULL) return false;
            node = node->children[curr];
        }

        return node->isTerminal;
    }
private:
    TrieNode* root;
};

class Solution{
public:
    bool isInstantaneous(vector<string>& codes){
        if(codes.size() == 0) return false;
        Trie* obj = new Trie(); 
        obj->insert(codes[0]);
        for(int i=1;i<codes.size();i++){
            for(int j=0;j<codes[i].size();j++){
                if(obj->search(codes[i].substr(0, j))) return false;
            }
            obj->insert(codes[i]);
        }
        return true;
    }

    float entropy(vector<float>& P){
        float result = 0;
        for(int i=0;i<P.size();i++) result += P[i]*log2(1/P[i]);
        return result;
    }

    float avLen(vector<string>& codes, vector<float>& P){
        float result = 0;
        for(int i=0;i<codes.size();i++) result += P[i]*(codes[i].size());
        return result;
    }

    float efficiency(float H, float L){
        return H/L;
    }

    float redundancy(float H, float L){
        return 1-(H/L);
    }
};

int main(){
    Solution sol;
    vector<string> codes = {"0","100","101","110","111","001"};
    vector<float> probabilites = {0.5, 0.25, 0.0625, 0.0625, 0.0625, 0.0625};
    bool instantaneous = sol.isInstantaneous(codes);
    if(instantaneous){
        cout<<"\nThe given code symbols are instantaneous.\n";
        float H = sol.entropy(probabilites);
        float L = sol.avLen(codes, probabilites);
        cout<<"Entropy: "<<H<<endl;
        cout<<"Average Length: "<<L<<endl;
        cout<<"Efficiency: "<<sol.efficiency(H, L)<<endl;
        cout<<"Redundancy: "<<sol.redundancy(H, L)<<endl;
    }
    else cout<<"The given code symbols are not instantaneous.";
    return 0;
}*/

// 2

/*class HuffmanNode{
public:
    string symbol;
    float probability;
    vector<HuffmanNode*> children;

    HuffmanNode(string S, float P){
        symbol = S;
        probability = P;
    }
};

struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->probability > b->probability;
    }
};

class Solution{
public:
    vector<string> result;
    priority_queue<HuffmanNode* , vector<HuffmanNode*>, Compare> pq;
    map<string, string> m;
    vector<pair<string, float>> symbols;

    vector<string> compactCodes(vector<int> code_alpha, vector<float> P){
        int n = code_alpha.size();
        int N = newSize(P.size(), n);
        int original_size = P.size();

        if(N != P.size()){
            for(int j=P.size();j<N;j++) P.push_back(0);
        }

        sort(P.begin(), P.end(), greater<>());
        
        for(int i=1;i<=P.size();i++){
            string str = "s";
            symbols.push_back({str+to_string(i), P[i-1]});
        }

        HuffmanNode* root = buildHuffmanTree(symbols, code_alpha.size());

        generateCodes(root, "", m);

        int j = 0;

        for (auto& pair : m) {
            if(j<original_size){
                result.push_back(pair.second);
                j++;
            }
            else break;
        }

        return result;
    }
private:
    int newSize(int n, int r){
        for(int i=0;;i++){
            int temp = r + i*(r-1);
            if(n <= temp) return temp;
        }
        return 0;
    }

    HuffmanNode* buildHuffmanTree(vector<pair<string, float>>& symbols, int numberOfChildren){
        for(int i=0;i<symbols.size();i++) pq.push(new HuffmanNode(symbols[i].first, symbols[i].second));

        while(pq.size() > 1){
            HuffmanNode* combined = new HuffmanNode("\0", 0);

            for(int i=0;i<numberOfChildren;i++){
                HuffmanNode* temp = pq.top();
                pq.pop();
                combined->children.push_back(temp);
                combined->probability += temp->probability;
            }

            pq.push(combined);
        }

        return pq.top();
    }

    void generateCodes(HuffmanNode* root, string code, map<string, string>& huffmanCodes){
        if(root == NULL) return;

        int n = root->children.size();

        if(n == 0){
            huffmanCodes[root->symbol] = code;
        }

        for(int i=0;i<n;i++){
            generateCodes(root->children[n-i-1], code+to_string(i), huffmanCodes);
        }
    }
};

int main(){
    Solution sol;
    vector<float> P = {0.111,0.111,0.111,0.111,0.111,0.111,0.111,0.111,0.111};
    // vector<float> P = {0.4, 0.3, 0.1, 0.1, 0.06, 0.04};
    // vector<float> P = {0.22,0.15,0.12,0.10,0.10,0.08,0.06,0.05,0.05,0.04,0.03};
    vector<int> code_alpha = {0,1,2,3};
    vector<string> result = sol.compactCodes(code_alpha, P);
    for(int i=0;i<result.size();i++){
        cout<<"s"+to_string(i+1)+":"<<"\t"<<result[i]<<endl;
    }
    return 0;
}*/

// 3

/*class Solution{
public:
    vector<float> P_b(vector<vector<float>>& BSC, vector<float>& P_a){
        vector<float> result;
        for(int i=0;i<BSC.size();i++){
            float temp = 0;
            for(int j=0;j<BSC[0].size();j++) temp += P_a[j]*BSC[j][i];
            result.push_back(temp);
        }
        return result;
    }

    vector<vector<float>> joint_probability(vector<vector<float>>& BSC, vector<float>& P_a){
        vector<vector<float>> result;
        vector<float> pB = P_b(BSC, P_a);
        for(int i=0;i<BSC.size();i++){
            vector<float> arr;
            for(int j=0;j<BSC[0].size();j++){
                float temp = P_a[i]*BSC[i][j];
                arr.push_back(temp);
            }
            result.push_back(arr);
        }
        return result;
    }

    vector<vector<float>> posteriori(vector<vector<float>>& BSC, vector<float>& P_a){
        vector<vector<float>> result;
        vector<float> pB = P_b(BSC, P_a);
        for(int i=0;i<BSC.size();i++){
            vector<float> arr;
            for(int j=0;j<BSC[0].size();j++){
                float temp = (P_a[i]*BSC[i][j])/pB[j];
                arr.push_back(temp);
            }
            result.push_back(arr);
        }
        return result;
    }

    float priori_entropy(vector<float>& P_a){
        float result = 0;
        for(int i=0;i<P_a.size();i++) result += P_a[i]*log2(1/P_a[i]);
        return result;
    }

    float posteriori_entropy(vector<vector<float>>& posteriori){
        float result = 0;
        for(int i=0;i<posteriori.size();i++){
            for(int j=0;j<posteriori[0].size();j++){
                result += posteriori[i][j]*log2(1/posteriori[i][j]);
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<vector<float>> BSC_P = {{0.66, 0.33},{0.1, 0.9}};
    vector<float> P_a = {0.75, 0.25};

    vector<float>pB = sol.P_b(BSC_P, P_a);
    vector<vector<float>> posteriori_result = sol.posteriori(BSC_P, P_a);
    vector<vector<float>> joint_probability_result = sol.joint_probability(BSC_P, P_a);
    float priori_entropy_result = sol.priori_entropy(P_a);
    float posteriori_entropy_result = sol.posteriori_entropy(posteriori_result);

    cout<<"\n"<<"P_b:"<<"\n\n";
    for(int i=0;i<pB.size();i++){
        cout<<"P(b="+to_string(i)+"):"<<"\t"<<pB[i]<<endl;
    }

    cout<<"\n"<<"P(ai/bj):"<<"\n\n";
    for(int i=0;i<posteriori_result.size();i++){
        for(int j=0;j<posteriori_result[0].size();j++){
            cout<<"P(a="+to_string(i)+"/b="+to_string(j)+"):"<<"\t"<<posteriori_result[i][j]<<endl;
        }
    }

    cout<<"\n"<<"P(ai,bj):"<<"\n\n";
    for(int i=0;i<joint_probability_result.size();i++){
        for(int j=0;j<joint_probability_result[0].size();j++){
            cout<<"P(a="+to_string(i)+",b="+to_string(j)+"):"<<"\t"<<joint_probability_result[i][j]<<endl;
        }
    }

    cout<<"\n"<<"Priori Entropy: "<<priori_entropy_result<<"\n\n";
    cout<<"\n"<<"Posteriori Entropy: "<<posteriori_entropy_result<<"\n\n";

    return 0;
}*/

// 4

/*class HuffmanNode{
public:
    string symbol;
    float probability;
    HuffmanNode* left = NULL;
    HuffmanNode* right = NULL;

    HuffmanNode(string S, float P){
        symbol = S;
        probability = P;
    }
};

struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->probability > b->probability;
    }
};

class Solution{
public:
    vector<string> result;
    priority_queue<HuffmanNode* , vector<HuffmanNode*>, Compare> pq;
    map<string, string> m;
    vector<pair<string, float>> symbols;

    vector<string> compactCodes(vector<int> code_alpha, vector<float> P){
        int n = code_alpha.size();
        
        for(int i=1;i<=P.size();i++){
            string str = "s";
            symbols.push_back({str+to_string(i), P[i-1]});
        }

        HuffmanNode* root = buildHuffmanTree(symbols);

        generateCodes(root, "", m);

        for (auto& pair : m) {
            result.push_back(pair.second);
        }

        return result;
    }

    float efficiency(vector<string>& codes, vector<float>& P){
        float H = entropy(P);
        float L = avLen(codes, P);
        return H/L;
    }

private:
    HuffmanNode* buildHuffmanTree(vector<pair<string, float>>& symbols){
        for(int i=0;i<symbols.size();i++) pq.push(new HuffmanNode(symbols[i].first, symbols[i].second));

        while(pq.size() > 1){
            HuffmanNode* left = pq.top();
            pq.pop();
            HuffmanNode* right = pq.top();
            pq.pop();

            HuffmanNode* combined = new HuffmanNode("\0", left->probability + right->probability);
            combined->left = left;
            combined->right = right;
            pq.push(combined);
        }

        return pq.top();
    }

    void generateCodes(HuffmanNode* root, string code, map<string, string>& huffmanCodes){
        if(root == NULL) return;

        if(!root->left && !root->right){
            huffmanCodes[root->symbol] = code;
        }

        generateCodes(root->left, code+"1", huffmanCodes);
        generateCodes(root->right, code+"0", huffmanCodes);
    }

    float entropy(vector<float>& P){
        float result = 0;
        for(int i=0;i<P.size();i++) result += P[i]*log2(1/P[i]);
        return result;
    }

    float avLen(vector<string>& codes, vector<float>& P){
        float result = 0;
        for(int i=0;i<codes.size();i++) result += P[i]*(codes[i].size());
        return result;
    }
};

int main(){
    Solution sol;
    vector<float> P = {0.4, 0.3, 0.1, 0.1, 0.06, 0.04};
    // vector<float> P = {0.111,0.111,0.111,0.111,0.111,0.111,0.111,0.111,0.111};
    vector<int> code_alpha = {0,1};
    vector<string> codes = sol.compactCodes(code_alpha, P);
    float efficiency = sol.efficiency(codes, P);
    for(int i=0;i<codes.size();i++) cout<<"\n"<<"s"+to_string(i+1)<<"\t"<<codes[i]<<"\n";
    cout<<"\nefficiency: "<<efficiency<<endl;
    return 0;
}*/

// 5

/*class Solution{
public:
    float channel_capacity(vector<vector<float>>& BSC, vector<float>& P_a){
        vector<vector<float>> P_a_b = joint_probability(BSC, P_a);
        vector<float> pB = P_b(BSC, P_a);

        float result = 0;

        for(int i=0;i<P_a_b.size();i++){
            for(int j=0;j<P_a_b[0].size();j++){
                result += (P_a_b[i][j])*log2(P_a_b[i][j]/(P_a[i]*pB[j]));
            }
        }

        return result;
    }
private:
    vector<float> P_b(vector<vector<float>>& BSC, vector<float>& P_a){
        vector<float> result;
        for(int i=0;i<BSC.size();i++){
            float temp = 0;
            for(int j=0;j<BSC[0].size();j++) temp += P_a[j]*BSC[j][i];
            result.push_back(temp);
        }
        return result;
    }

    vector<vector<float>> joint_probability(vector<vector<float>>& BSC, vector<float>& P_a){
        vector<vector<float>> result;
        vector<float> pB = P_b(BSC, P_a);
        for(int i=0;i<BSC.size();i++){
            vector<float> arr;
            for(int j=0;j<BSC[0].size();j++){
                float temp = P_a[i]*BSC[i][j];
                arr.push_back(temp);
            }
            result.push_back(arr);
        }
        return result;
    }

};

int main(){
    Solution sol;
    vector<vector<float>> BSC = {{0.66, 0.33},{0.1, 0.9}};
    vector<float> P_a = {0.75, 0.25};
    cout<<"\nChannel Capacity: "<<sol.channel_capacity(BSC, P_a)<<endl;
    return 0;
}*/