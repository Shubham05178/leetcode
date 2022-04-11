/**
* Leetcode Problem - https://leetcode.com/problems/wildcard-matching/
* Author - Shubham Nagaria
* Date - 12th April 2022
Wildcard Matching
**/
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        bool dp[n+1][m+1];
        dp[0][0] = true;
        for(int i =0; i <= n;++i){
            for(int j =0 ; j<=m ; ++j){
                if(i == 0 && j == 0) continue;
                else if(i == 0){
                    if(p[j-1]=='*') dp[i][j] = dp[i][j-1];
                    else
                        dp[i][j] = false;
                    continue;
                }
               else if(j == 0){
                    dp[i][j] = false;
                    continue;
            }
            else{
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if ( p[j-1]=='*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};