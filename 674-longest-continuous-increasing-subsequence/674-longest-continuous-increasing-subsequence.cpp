/**
* Leetcode Problem - https://leetcode.com/problems/longest-continuous-increasing-subsequence/
* Author - Shubham Nagaria
* Date - 10th April 2022
Longest Continuous Increasing Subsequence
**/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size(), maxi = 1;
        int l = 1;
        for(int i =1 ; i < n ; i++){
            if(nums[i-1]<nums[i])
                l++;
            else
                l = 1;
            maxi = max(maxi,l);
        }
        return maxi;
    }
};