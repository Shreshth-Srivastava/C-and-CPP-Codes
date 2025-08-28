// My solution

bool isAnagram(char* s, char* t) {
   if(strlen(s) != strlen(t)) return false;
    else{
        int count1[26] = {0},count2[26] = {0};
        for(int i = 0;s[i];i++) count1[s[i] - 'a']++;
        for(int i = 0;t[i];i++) count2[t[i] - 'a']++;
        for(int i = 0;i<26;i++){
            if(count1[i] != count2[i]) return false;
        }
        return true;
    }
}

// Slightly different approach

// bool isAnagram(char* s, char* t) {
//     int i=0,n=strlen(s),m=strlen(t);
//     if(n!=m)
//         return false;
//     int freq[26] = {0};
//     int offset = (int)'a';
//     for(i;i<n;i++)
//     {
//         freq[s[i]-offset]++;
//         freq[t[i]-offset]--;
//     }
//     for(i=0;i<26;i++)
//         if(freq[i]!=0)
//             return false;
//     return true;
// }
