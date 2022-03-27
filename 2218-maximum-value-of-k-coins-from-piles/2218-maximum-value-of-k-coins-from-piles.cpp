/**
* Leetcode Problem - https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/
* Author - Shubham Nagaria
* Date - 27th March 2022
Maximum Value of K Coins From Piles
**/
class Solution {
public:
    int dp[2001][2001];
    int solve(int i,vector<vector<int>>& piles, int k){
        if(i >= piles.size() || k == 0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int maxi = 0, sum = 0;
        maxi = max(maxi, solve(i+1,piles,k));
        for(int j =0; j <piles[i].size();j++){
            sum+= piles[i][j];
            if(k>=(j+1)) maxi = max(maxi, sum+solve(i+1,piles, k-(j+1)));
        }
        dp[i][k]=maxi;
        return dp[i][k];
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,piles,k);
    }
};