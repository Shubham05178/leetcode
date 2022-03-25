/**
* Leetcode Problem - https://leetcode.com/problems/coin-change-2/
* Author - Shubham Nagaria
* Date - 25th March 2022
 Coin Change 2
**/
class Solution {
public:
    int countCoins(vector<vector<int>> &dp, int n, vector<int>& coins, int amount ){
        if( amount == 0) return 1;
        if(n==-1) return 0;
        if(dp[n][amount] != -1 ) return dp[n][amount];
        dp[n][amount] = 0;
        if(amount - coins[n] >=0)
            dp[n][amount] += countCoins(dp,n,coins,amount- coins[n]);
        dp[n][amount] += countCoins(dp, n-1,coins, amount);
        return dp[n][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n =coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return countCoins(dp, n-1 , coins, amount);
    }
};