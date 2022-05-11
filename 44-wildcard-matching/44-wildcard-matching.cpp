class Solution {
public:
    bool isMatch(string s, string p) {
        int size1 = s.size();
        int size2 = p.size();
        bool dp[size1 + 1][size2 + 1];
        dp[0][0] = true;
        for(int idx = 0 ; idx <= size1 ; idx++) {
            for(int idy = 0; idy <= size2; idy++) {
                if( idx == 0 && idy == 0) continue;
                if(idx == 0){
                    if(p[idy-1] == '*') dp[idx][idy] = dp[idx][idy - 1];
                    else dp[idx][idy] = false;
                    continue;
                }
                if(idy == 0){
                    dp[idx][idy] = false;
                    continue;
                }
                if(( p[idy - 1] == s[idx - 1] ) || p[idy -1]=='?')
                    dp[idx][idy] = dp[idx - 1][idy - 1];
                else if(p[idy - 1] == '*')
                    dp[idx][idy] = dp[idx - 1][idy] || dp[idx][idy - 1];
                else
                    dp[idx][idy]= false;
            }
        }
        return dp[size1][size2];
    }
};