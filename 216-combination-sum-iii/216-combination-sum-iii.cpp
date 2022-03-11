/**
* Leetcode Problem - https://leetcode.com/problems/combination-sum-iii/
* Author - Shubham Nagaria
* Date - 11th March 2022
Combination Sum III
**/
class Solution {
public:
    void createCombinations(vector<vector<int>> &res, vector<int> &temp, int i,int sum,int k,int n){
        if(temp.size()==k){
            if(sum == n) res.push_back(temp);
            return;
        }
        for(int j = i; j < 10; j++){
            sum += j;
            temp.push_back(j);
            createCombinations(res,temp,j+1,sum,k,n);
            sum -= j;
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>>res;
        createCombinations(res,temp,1,0,k,n);
        return res;
    }
};