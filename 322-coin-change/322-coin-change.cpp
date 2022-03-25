/**
* Leetcode Problem - https://leetcode.com/problems/coin-change/
* Author - Shubham Nagaria
* Date - 25th March 2022
Coin Change
**/
class Solution {
public:
    long long int countCoins(vector<vector<long long int>> &dp,vector<int> &coins, int amount, int n){
        if(amount == 0) return 0;
            if( n == -1) return INT_MAX;
        if(dp[n][amount]!= -1) return dp[n][amount];
        
        if(coins[n] <= amount) 
            dp[n][amount] = min( 1LL+countCoins(dp, coins, amount - coins[n],n), countCoins(dp,coins,amount,n-1));
        else 
            dp[n][amount] = countCoins(dp,coins,amount,n-1);
        
        return dp[n][amount];
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<long long int>>dp(n, vector<long long int>(amount+1,-1));
        int x= countCoins(dp, coins, amount, n-1);
        return x ==INT_MAX ? -1: x;
    }
};