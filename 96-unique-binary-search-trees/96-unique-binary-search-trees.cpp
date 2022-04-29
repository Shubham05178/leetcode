/**
Concept of Catalan Number works here !!
C0 = 1
C1 = 1
C2 = C0*C1 + C1*C0 = 1*1 + 1*1 = 2 
C3 = C0*C2 + C1*C1 + C2*C0 = 1*2 + 1*1 + 2*1 = 5
C4 = C0*C3 + C1*C2 + C2*C1 + C3*C0 = 1*5 + 1*2 + 2*1 + 5*1 = 14
C5 = C0*C4 + C1*C3 + C2*C2 + C3*C1 + C4*C0 = 1*14 + 1*5 + 2*2 + 5*1 + 14*1 = 42

let's understand how to iterate.
for calculating C2 i.e, dp[2]
dp[2]= d[0]*dp[1] + dp[1] * dp[0]

for (end 2 to n)
    for (start 0 to end-1)
        dp[end] += dp[start] * dp[end - 1 - start] 
**/

class Solution {
public:
    int numTrees(int n) {
        if(n <= 1)
            return 1;
        vector<int>dp(n+1);
        dp[0] = dp[1] = 1;
        for(int end = 2; end <= n; ++end) {
            for(int start = 0; start < end; ++start) {
                dp[end] += (dp[start] * dp[end - 1 - start]);
            }
        }
        return dp[n];
    }
};