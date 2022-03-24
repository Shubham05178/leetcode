/**
* Leetcode Problem - https://leetcode.com/problems/count-square-submatrices-with-all-ones/
* Author - Shubham Nagaria
* Date - 25th March 2022
Count Square Submatrices with All Ones
**/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int count = 0;
        int jtemp, height,width,calH;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(i != 0 && matrix[i][j]) matrix[i][j] += matrix[i-1][j];
                if(matrix[i][j]){ 
                    count++;
                    height = matrix[i][j];
                    for(int width = 2; width <= height; width++){
                        jtemp = j-1;
                        calH = 1;
                        while(jtemp >= 0 && calH < width){
                            if(matrix[i][jtemp] < width) break;
                            calH++;
                            jtemp--;
                        }
                        if(calH == width) {
                            count++;
                        }
                     }
                }
            }
        }
    return count;
    }
};