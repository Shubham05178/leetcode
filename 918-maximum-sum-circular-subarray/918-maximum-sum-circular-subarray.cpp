/**
* Leetcode Problem - https://leetcode.com/problems/maximum-sum-circular-subarray/
* Author - Shubham Nagaria
* Date - 22nd April 2022
Maximum Sum Circular Subarray
**/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum0 = 0, sum1 = 0,sum2 = 0, maxi = INT_MIN, mini = INT_MAX;
        for(int i : nums){
            sum0  +=i;
            sum1 +=i;
            sum2 +=i;
            if(maxi < sum1) maxi= sum1;
            if(sum1 < 0) sum1 = 0;
            if(sum2 < mini) mini = sum2;
            if(sum2 > 0) sum2 = 0;
        }
        return (max(maxi,sum0-mini == 0 ? mini : sum0-mini));
    }
};