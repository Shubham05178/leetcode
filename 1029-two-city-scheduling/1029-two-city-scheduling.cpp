/**
* Leetcode Problem - https://leetcode.com/problems/two-city-scheduling/
* Author - Shubham Nagaria
* Date - 25th March 2022
Two City Scheduling
**/
class Solution {
public:
    bool static comp(vector<int> &a, vector<int> &b){
        return a[0]-a[1] < b[0]-b[1];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),comp);
        int n = costs.size()/2, res = 0;
        for(int i =0; i < n;i++) res += costs[i][0]+costs[i+n][1]; 
        return res;
    }
};