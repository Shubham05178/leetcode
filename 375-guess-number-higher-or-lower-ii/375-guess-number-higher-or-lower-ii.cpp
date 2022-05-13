class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[n+2][n+1], currMin, end;
        memset(dp,0,sizeof(dp));
        for(int len = 2; len <= n; ++len) {
            for(int start = 1; start <= n - len + 1; ++start) {
                end = start + len -1;
                currMin = INT_MAX;
                for(int pivot = start; pivot <= end; ++pivot ){
                    currMin = min(currMin, pivot + max(dp[start][pivot - 1], dp[pivot + 1][end]));
                }
                dp[start][end]= currMin;
            }
        }
        return dp[1][n];
    }
};