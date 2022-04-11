/**
* Leetcode Problem - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
* Author - Shubham Nagaria
* Date -  11th April 2022
Best Time to Buy and Sell Stock II
**/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int profit = 0, n = prices.size();
        for(int i = 1; i < n; i++){
            if(prices[i]>prices[i-1])
                profit+= prices[i]-prices[i-1];
        }
        return profit;
    }
};