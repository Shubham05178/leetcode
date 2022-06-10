class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int idy = 0, maxi = 0, idx = 0, n = s.size();
        while(idx < n) {
            freq[s[idx]]++;
            while(freq[s[idx]] > 1 && idy <= idx){
                freq[s[idy]]--;
                idy++;
            }
            if(idx - idy + 1 > maxi){
                maxi = idx - idy + 1;
            }
            idx++;
        }
        return maxi;
    }
};