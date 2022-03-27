/**
* Leetcode Problem - https://leetcode.com/problems/integer-break/
* Author - Shubham Nagaria
* Date - 27th March 2022
Integer Break
**/
class Solution {
public:
    vector<vector<int>>dp;
    int func(int n, int splits,vector<vector<int>> &dp){
        if(splits == 0 && n <= 1)
            return 0;
        if(n<=1) 
            return 1;
        if(dp[n][splits>0] != -1) 
            return dp[n][splits>0];
        int maxi = 0;
        int m = n;
        if(splits > 0) m++;
        for(int i = 1; i< m;i++)
            maxi= max(maxi,i * func(n - i, splits+1,dp));
        dp[n][splits>0] = maxi;
        return maxi;
    }
    int integerBreak(int n) {
         vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return func(n,0,dp);
    }
};