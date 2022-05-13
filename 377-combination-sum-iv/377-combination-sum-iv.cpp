class Solution {
public:
    int dfs(vector<int>& nums, int target, int dp[]){
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;
        if(dp[target] != -1)
            return dp[target];
        int count = 0;
        for(int coin : nums){
            count += dfs(nums, target - coin, dp);
        }
        return dp[target] = count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int dp[target + 1];
        memset(dp, -1, sizeof(dp));
        return dfs(nums, target, dp);
    }
};