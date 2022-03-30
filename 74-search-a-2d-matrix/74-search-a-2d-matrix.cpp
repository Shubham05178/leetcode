/**
* Leetcode Problem - https://leetcode.com/problems/search-a-2d-matrix/
* Author - Shubham Nagaria
* Date - 30th March 2022
Search a 2D Matrix
**/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        while(i<n && i>=0 && j >=0 && j<m){
            if(matrix[i][j]== target)
                return true;
            else if(matrix[i][j]< target)
                i++;
            else
                j--;
        }
        return false;
    }
};