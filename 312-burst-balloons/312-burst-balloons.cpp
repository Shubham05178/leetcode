/**
* Leetcode Problem - https://leetcode.com/problems/burst-balloons/
* Author - Shubham Nagaria
* Date - 11th April 2022
Burst Balloons
**/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int>num(1,1);
        num.insert(num.end(),nums.begin(),nums.end());
        num.push_back(1);
        int n = num.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int win =1; win <= n-1;win++){
            for(int left =1; left < n-win; left++){
                int right = left+win-1;
                for(int i = left ; i<=right;i++){
                    dp[left][right] = max(dp[left][right], num[left-1] * num[i] * num[right+1] + dp[left][i-1] + dp[i+1][right]); 
                }
            }
        }
        return dp[1][n-2];
    }
};