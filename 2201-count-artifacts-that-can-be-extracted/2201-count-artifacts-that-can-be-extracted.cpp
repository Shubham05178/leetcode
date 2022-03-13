/**
* Leetcode Problem - https://leetcode.com/contest/weekly-contest-284/problems/count-artifacts-that-can-be-extracted/
* Author - Shubham Nagaria
* Date - 13th March 2022
Count Artifacts That Can Be Extracted
**/
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>>mat(n,vector<int>(n,0));
        for(auto i: dig)
            mat[i[0]][i[1]]=1;
        int count =0;
        for(auto i: artifacts){
            int countcell = 0;
            for(int j =i[0]; j <= i[2]; j++){
                for(int l=i[1]; l<= i[3];l++){
                    if(mat[j][l]==1){
                        countcell++;
                    }
                }
            }
            if(countcell == (i[2]+1 -i[0])*(i[3]+1-i[1])) count++;
        }
        return count;
    }
};