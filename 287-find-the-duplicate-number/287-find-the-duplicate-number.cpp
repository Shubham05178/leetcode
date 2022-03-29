/**
* Leetcode Problem - https://leetcode.com/problems/find-the-duplicate-number/
* Author - Shubham Nagaria
* Date - 29th March 2022
Find the Duplicate Number
**/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n =nums.size();
        for(int i =0 ; i <n; i++){
            int cur=abs(nums[i]);
            if(nums[cur]<0)
                return cur;
            nums[cur]*=-1;
            
        }
        return 0;
    }
};
        