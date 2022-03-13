/**
* Leetcode Problem - https://leetcode.com/contest/weekly-contest-284/problems/find-all-k-distant-indices-in-an-array/
* Author - Shubham Nagaria
* Date - 13th March 2022
Find All K-Distant Indices in an Array
**/
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>indices,res;
        int n = nums.size();
        for(int i =0 ; i < n; i++){
            if(nums[i]==key)
                indices.push_back(i);
        }
        for(int i=0; i < n; i++){
            for(auto ind: indices){
                if(abs(i-ind)<=k){
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};