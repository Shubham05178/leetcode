/**
* Leetcode Problem - https://leetcode.com/problems/combination-sum/
* Author - Shubham Nagaria
* Date - 11th March 2022
Combination Sum
**/
class Solution {
public:
    void createCombinations(vector<int>&temp, vector<int>&candidates, vector<vector<int>>&res, int i, int n, int sum,int target){
        if(sum == target){
            res.push_back(temp);
            return;
        }
        if(sum > target) return;
        for(int j = i; j < n; j++){
            sum += candidates[j];
            temp.push_back(candidates[j]);
            createCombinations(temp, candidates, res, j, n, sum, target);
            sum -= candidates[j];
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>res;
        int sum = 0;
        createCombinations(temp, candidates, res, 0, candidates.size(), sum, target);
        return res;
    }
};