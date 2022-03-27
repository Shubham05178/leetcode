/**
* Leetcode Problems - https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
* Author - Shubham Nagaria
* Date - 27th March 2022
The K Weakest Rows in a Matrix
**/
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>res;
        int n = mat.size();
        int m = mat[0].size();
        for(int i =0; i < n;i++){
            for(int j = m-2 ; j>=0; j--){
                mat[i][j] += mat[i][j+1];
            }
        res.push_back({mat[i][0],i});
        }
        sort(res.begin(),res.end());
        vector<int>re;
        int i = 0;
        while(i<k){
            re.push_back(res[i].second);
            i++;
        }
        return re;
    }
};