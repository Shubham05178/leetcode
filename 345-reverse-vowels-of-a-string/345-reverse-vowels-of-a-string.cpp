class Solution {
public:
    string reverseVowels(string s) {
        string vow="", rev="";
        unordered_set<char> st = {'a','e','o','i','u','A','E','I','O','U'};
        for(char ch : s) {
            if(st.find(ch) != st.end())
                vow += ch;
        }
        int j = vow.size();
        for(char ch : s){
            if(st.find(ch) != st.end())
                rev += vow[--j]; 
            else
                rev += ch;
        }
        return rev;
    }
};