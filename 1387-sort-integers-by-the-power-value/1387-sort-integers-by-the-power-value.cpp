/**
* Leetcode Problem - https://leetcode.com/problems/sort-integers-by-the-power-value/
* Author - Shubham Nagaria
* Date - 23rd April 2022
Sort Integers by The Power Value
**/
class Solution {
public:
    int noofsteps(int n){
        if(n ==1)
            return 0;
        if(n%2)
            return 1+noofsteps(n*3+1);
    
        return 1+ noofsteps(n/2);
    }
    int getKth(int lo, int hi, int k) {
        vector<vector<int>>res;
        for(int i = lo ; i <=hi;i++){
            res.push_back({noofsteps(i),i});
        }        
       sort(res.begin(),res.end());
        return res[k-1][1];
    }
};