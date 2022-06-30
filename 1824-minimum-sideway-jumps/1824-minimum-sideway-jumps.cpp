class Solution {
public:
    int solver(vector<int> &obs, int idx, int n, int lane, vector<vector<int>> &dp){
        if(idx == n - 1)
            return 0;
        if(obs[idx] == lane)
            return INT_MAX-100;
        if(dp[idx][lane - 1] != -1)
            return dp[idx][lane - 1];
        if(obs[idx+1]!=lane){
            dp[idx][lane - 1] = solver(obs, idx + 1, n, lane, dp);
        }
        else{
            int l1,l2;
            if(lane == 1){
                l1=2;
                l2=3;
            }
            else if(lane == 2){
                l1=1;
                l2=3;
            }
            else{
                l1=1;
                l2=2;
            }
            dp[idx][lane - 1] = 1;
            dp[idx][lane -1]+= min(solver(obs, idx ,n, l1,dp), solver(obs, idx, n , l2, dp));
        }
        return dp[idx][lane-1];
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>>dp(n, vector<int>(3,-1));
        return solver(obstacles, 0, n, 2, dp);
    }
};