class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k) return false;
        unordered_set<string>se;
        for(int idx = 0; idx < s.size() - k + 1; idx++)
            se.insert(s.substr(idx,k));
        return se.size() == (1<<k);
    }
};