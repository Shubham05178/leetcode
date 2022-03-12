/**
* Leetcode Problem - https://leetcode.com/problems/permutations/
* Author - Shubham Nagaria
* Date - 13th March 2022
Permutations
**/
class Solution {
public:
    void Permutations(int i, int n,vector<int> &nums, vector<vector<int>> &res){
        if(i == n) res.push_back(nums);
        for(int j = i; j < n; j++){
            swap(nums[i],nums[j]);
            Permutations(i+1, n,nums,res);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        Permutations(0,nums.size(),nums,res);
        return res;
    }
};