/**
* Leetcode Problem - https://leetcode.com/problems/maximum-sum-circular-subarray/
* Author - Shubham Nagaria
* Date - 22nd April 2022
Maximum Sum Circular Subarray
**/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sumi =0;
        int su=0;
        int maxi = INT_MIN;
        for(int i:nums){
            su+=i;
            if(maxi<su)
                maxi= su;
            if(su<0)
                su=0;
        }
        su=0;
        int mini= INT_MAX;
        for(int i :nums){
            sumi +=i;
            su+= i;
            if(su<mini){
                mini = su;
            }
            if(su>0)
                su =0;
        }
        return (max(maxi,sumi-mini == 0 ? mini : sumi-mini));
    }
};