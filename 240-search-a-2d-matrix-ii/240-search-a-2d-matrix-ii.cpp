class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col = matrix[0].size() - 1 , size = matrix.size();
        while(row >= 0&& row < size && col >= 0){
            if(target == matrix[row][col])
                return true;
            else if(target > matrix[row][col]) {
                row++;                
            }
            else
                col--;
        }
    return false;
    }    
};


/**           ij
[[1,4,7,11,15]
[2,5,8,12,19]
[3,6,9,16,22]
[10,13,14,17,24]
[18,21,23,26,30]] 
**/