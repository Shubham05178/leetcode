/**
* Leetcode Problem - https://leetcode.com/problems/longest-increasing-subsequence/
* Author - Shubham Nagaria
* Date - 10th April 2022
Longest Increasing Subsequence
**/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), low, high, mid, ans, l = 0;
        vector<int>dp(n,INT_MIN);
        for(int i = 0;i < n;i++){
            if(i ==0){
                dp[l]= nums[i];
                l++;
            }
            else{
                if(dp[l-1] < nums[i]){
                    dp[l]= nums[i];
                    l++;
                }
                else{
                    low = 0, high = l-1, mid,ans = 0;
                    while(low<=high){
                        mid = low + ((high -low)>>1);
                        if(nums[i] <= dp[mid]){
                            ans = mid;
                            high = mid -1;
                        }
                        else{
                            low = mid+1;
                        }
                    }
                    dp[ans]=nums[i];
                }
            }
        }
        return l;
    }
};