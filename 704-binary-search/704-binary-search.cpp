/**
* Leetcode Problem - https://leetcode.com/problems/binary-search/
* Author - Shubham Nagaria
* Date - 26th March 2022
Binary Search
**/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size()-1, mid;
        while(l<=h){
            mid = l + ((h - l)>>1);
            if(nums[mid] == target) return mid;
            else if(nums[mid]<target) l = mid + 1;
            else h = mid - 1;
        }
        return -1;
    }
};