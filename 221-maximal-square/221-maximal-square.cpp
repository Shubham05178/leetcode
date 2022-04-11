/**
* Leetcode Problem - https://leetcode.com/problems/maximal-square/
* Author - Shubham Nagaria
* Date - 11th April 2022
Maximal Square
**/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0, n = matrix.size(), m = matrix[0].size();
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < n; i++){
            for(int j =0; j < m;j++){
                if(i ==0 || j == 0){
                    dp[i][j]= (matrix[i][j] =='1' ? 1:0);
                  }
                 else if(matrix[i][j]=='1'){
                     dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                  }
                maxi = max(maxi, dp[i][j] );
            }
        }
        return maxi * maxi;
    }
};