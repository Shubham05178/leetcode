/**
* Leetcode Problem -https://leetcode.com/problems/unique-binary-search-trees/ 
* Author - Shubham Nagaria    
* Date - 3rd April 2022
Unique Binary Search Trees
**/
class Solution {
public:
    int numTrees(int n) {
        if(n<=1) return 1;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=dp[1]=1;
        for(int i =2; i <=n; i++){
            for(int j =0;j<i;j++){
                dp[i] += dp[j] * dp[i-1-j];
            }
        }
        return dp[n];
    }
};