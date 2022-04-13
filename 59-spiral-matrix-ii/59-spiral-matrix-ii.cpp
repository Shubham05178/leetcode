/**
* Leetcode Problem - https://leetcode.com/problems/spiral-matrix-ii/
* Author - Shubham Nagaria
* Date - 13th April 2022
Spiral Matrix II
**/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        int row = n-1, col = n-1, startrow = 0, startcol = 0, k = 1;
          while(k<=n*n){
             for(int i = startcol ; i <= col; i++)
                 matrix[startrow][i] = k++;
            startrow++;
            for(int i = startrow; i <= row; i++)
                matrix[i][col] = k++;
            col--;
            for(int i = col; i >= startcol; i--)
                matrix[row][i] = k++;
            row--;
            for(int i = row; i >= startrow; i--)
                matrix[i][startcol] = k++;   
             startcol++;
          }
        return matrix;
    }
};