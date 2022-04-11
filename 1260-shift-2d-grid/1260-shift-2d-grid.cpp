/**
* Leetcode Problem - https://leetcode.com/problems/shift-2d-grid/
* Author - Shubham Nagaria
* Date - 11th April 2022
Shift 2D Grid
**/
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int l = n * m;
        vector<int>res;
        if(k%l ==0)
            return grid;
        int noofshifts= l-(k%l);
        for(int i =0; i < n ; i++){
            for(int j =0;j< m; j++){
                res.push_back(grid[i][j]);
            }
        }
        
        for(int i = 0; i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]= res[noofshifts%l];
                noofshifts++;
            }
        }
        return grid;
    }
};