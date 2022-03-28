/**
* Leetocode Problem - https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
* Author - Shubham Nagaria
* Date - 28th March 2022
Search in Rotated Sorted Array II
**/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l = 0, h = nums.size() - 1, mid;
        while(l <= h){
            mid = l + (( h - l) >> 1);
            if(nums[mid] == target) 
                return true;
            else if(nums[mid] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};