/**
* Leetcode Problem - https://leetcode.com/problems/permutations-ii/
* Author - Shubham Nagaria
* Date - 13th March 2022
Permutations II
**/
class Solution {
public:
    void Permutations(int i, int n, set<vector<int>> &s, vector<int>& nums){
        if(i == n) s.insert(nums);
        for(int j = i; j < n; j++){
            swap(nums[i],nums[j]);
            Permutations(i+1, n , s, nums);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>s;
        Permutations(0, nums.size(), s, nums);
        vector<vector<int>>res(s.begin(),s.end());
        return res;
    }
};