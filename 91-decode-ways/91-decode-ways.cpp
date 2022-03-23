/**
* Leetcode Problem - https://leetcode.com/problems/decode-ways/
* Author - Shubham Nagaria
* Date - 23rd March 2022
Decode Ways
**/
class Solution {
public:
     int decodeWays(int i, int dp[], string &s){
        if( i == -1) {
            return 1;
        }
        if(dp[i] != -1) return dp[i];
        dp[i] = 0;
        if(i >= 0){
            if(s[i] > '0' && s[i] <= '9') dp[i] += decodeWays(i - 1, dp, s);
        }
        if(i > 0){
            int val = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if(val > 9 && val <= 26) dp[i] += decodeWays(i - 2, dp, s);
        }
        return dp[i];
    }
    int numDecodings(string s) {
        int n = s.size();
        int dp[n];
        memset(dp, -1, sizeof(dp));
        return decodeWays(n - 1, dp, s);
    }
};