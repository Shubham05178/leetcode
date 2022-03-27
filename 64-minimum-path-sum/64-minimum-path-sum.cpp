/**
* Leetcode Problem - https://leetcode.com/problems/minimum-path-sum/
* Author - Shubham Nagaria
* Date - 27th March 2022
Minimum Path Sum
**/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n;i++){
            for(int j =0;j<m; j++){
                if(i==0 && j ==0)continue;
                if(i==0)
                    grid[i][j] += grid[i][j-1];
                else if(j==0)
                    grid[i][j] += grid[i-1][j];
                else
                    grid[i][j]+= min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[n-1][m-1];
    }
};