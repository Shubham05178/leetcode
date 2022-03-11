/**
* Leetcode Problem - https://leetcode.com/problems/combination-sum-ii/
* Author - Shubham Nagaria
* Date - 11th March 2022
Combination Sum II
**/
class Solution {
public:
    void createCombinations(vector<pair<int,int>> &arr, vector<int> &temp, vector<vector<int>> &res ,int i, int n , int sum, int target){
        if(target == sum){
            res.push_back(temp);
            return;
        }
        if(sum>target) return;
        for(int j = i; j < n; j++){
            sum += arr[j].first;
            arr[j].second--;
            temp.push_back(arr[j].first);
            if(arr[j].second > 0) createCombinations(arr,temp,res,j,n,sum,target);
            else createCombinations(arr,temp,res,j+1,n,sum,target);
            temp.pop_back();
            sum -= arr[j].first;
            arr[j].second++;
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int,int>countfreq;
        vector<pair<int,int>>arr;
        for(int i: candidates) countfreq[i]++;
        
        for(auto i: countfreq) arr.push_back({i.first,i.second});
        
        vector<vector<int>>res;
        vector<int>temp;
        int n = arr.size(), sum = 0;
        createCombinations(arr,temp,res,0,n,sum,target);
        return res;
        
    }
};