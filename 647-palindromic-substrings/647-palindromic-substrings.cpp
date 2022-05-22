class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int center = 0; center < s.size();){
            int r = center; 
            while(r < s.size() and s[r] == s[center])
                r++;
            int len = r - center; ans += len * (len + 1) / 2; 
            int l = center - 1; center = r;
            while( l >= 0 and r < s.size() and s[l] == s[r])
                l--, r++, ans++;
        }
        return ans;
    }
};