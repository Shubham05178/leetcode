/**
* Leetcode Problem - https://leetcode.com/problems/count-number-of-teams/
* Author - Shubham Nagaria
* Date - 26th March 2022
Count Number of Teams
**/
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0, n = rating.size();
        for(int i = 1; i < n-1 ; i++){
            int lesser[2]={}, greater[2]={};
            for(int j =0; j < n ; j++){
                if(rating[i]<rating[j])
                    lesser[i < j]++;
                if(rating[i]>rating[j])
                    greater[i<j]++;
            }
            res+= lesser[0]*greater[1] + lesser[1]*greater[0];
        }
        return res;
    }
};