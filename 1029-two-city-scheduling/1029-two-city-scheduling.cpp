/**
* Leetcode Problem - https://leetcode.com/problems/two-city-scheduling/
* Author - Shubham Nagaria
* Date - 25th March 2022
Two City Scheduling
**/
class Solution {
public:
    int twoCityCostOptimum(vector<vector<int>> &costs, int a, int b, int n,unordered_map<string,int>&dp){
        if(a == 0 && b == 0) return 0;
        string s = to_string(a) + "_" + to_string(b);
        if(dp.find(s) != dp.end()) return dp[s];
        if(a == 0) dp[s] = costs[n][1] + twoCityCostOptimum(costs, a, b-1, n-1, dp);
        else if(b == 0) dp[s] = costs[n][0] + twoCityCostOptimum(costs, a-1, b, n-1, dp);
        else dp[s] = min(costs[n][0]+twoCityCostOptimum(costs, a-1, b, n-1, dp), costs[n][1]+twoCityCostOptimum(costs, a, b-1, n-1, dp));
        return dp[s];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        unordered_map<string,int>dp;
        return twoCityCostOptimum(costs, n/2, n/2, n-1, dp);
    }
};