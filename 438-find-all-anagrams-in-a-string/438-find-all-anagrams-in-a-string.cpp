class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int need = p.size(), nsize = s.size();
        int msize = need;
        vector<int>res,words(26);
        for(char ch : p)
            words[ch-'a']++;
        for(int idx = 0 ; idx < nsize; idx++) {
            if(idx - msize >= 0 && ++words[s[idx - msize]-'a']> 0 )
                need++;
            words[s[idx]-'a']--;
            if(words[s[idx]-'a']>-1)
                need--;
            if(need == 0)
                res.push_back(idx - msize + 1);
        }
        return res;
    }
};