/**
* Leetcode Problem - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
* Author - Shubham Nagaria
* Date - 11th April 2022
Best Time to Buy and Sell Stock
**/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX, maxi=0;
        for(int i : prices){
            mini = min(mini, i);
            maxi = max(maxi, i - mini);
        }
        return maxi;
    }
};