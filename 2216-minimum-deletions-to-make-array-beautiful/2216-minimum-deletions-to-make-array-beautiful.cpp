/**
* Leetcode Problem - https://leetcode.com/contest/weekly-contest-286/problems/minimum-deletions-to-make-array-beautiful/
* Author - Shubham Nagaria
* Date - 28th March 2022
Minimum Deletions to Make Array Beautiful
**/
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int count=0, n = nums.size();
        for(int i =0; i < n; i++){
          if((i - count) %2 == 0 && i+1 < n && nums[i]== nums[i+1]){
              count++;
          }  
        }
        if((n-count) % 2 == 1)
            count++;
    return count;
    }
};