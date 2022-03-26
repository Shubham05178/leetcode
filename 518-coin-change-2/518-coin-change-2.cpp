/**
* Leetcode Problem - https://leetcode.com/problems/coin-change-2/
* Author - Shubham Nagaria
* Date - 26th March 2022
 Coin Change 2
**/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[amount + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= amount; j++){
                if(coins[i] <= j)
                    dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};