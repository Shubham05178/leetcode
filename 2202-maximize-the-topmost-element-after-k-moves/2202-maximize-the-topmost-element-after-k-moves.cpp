/**
* Leetcode Problem - https://leetcode.com/contest/weekly-contest-284/problems/maximize-the-topmost-element-after-k-moves/
* Author - Shubham Nagaria
* Date - 13th March 2022
Maximize the Topmost Element After K Moves
**/
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0) return n>=1 ? nums[0] : -1;
        if(k==1) return n>1 ? nums[1]:-1;
        if(n==1) return k%2 ? -1: nums[0];
        int maxi = *max_element(nums.begin(),nums.begin()+min(k-1,n));
        if(k<n) maxi = max( maxi, nums[k]);
        return maxi;
    }
};