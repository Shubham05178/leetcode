class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int noOfRows = matrix.size();
        int noOfColumns = matrix[0].size();
        bool isFirstRowHoldZero = false, isFirstColumnHoldZero = false;
        
        // checking whether first column hold any zero
        for(int indexRow = 0; indexRow < noOfRows; indexRow++){
            if(matrix[indexRow][0] == 0) 
                isFirstColumnHoldZero = true;
        }
        // checking whether first row hold any zero
        for(int indexCol = 0; indexCol < noOfColumns; indexCol++){
            if(matrix[0][indexCol] == 0)
                isFirstRowHoldZero = true;
        }
        // Traverse over matrix find zero and mark that row and column
        for(int indexRow = 0; indexRow < noOfRows; indexRow++){
            for(int indexCol = 0; indexCol < noOfColumns; indexCol++){
                if(matrix[indexRow][indexCol] == 0){
                    matrix[indexRow][0] = 0;
                    matrix[0][indexCol] = 0;
                }
            }
        }
        // Traverse for first col
        for(int indexRow = 1; indexRow < noOfRows; indexRow++){
            if(matrix[indexRow][0] == 0){
                for(int indexCol = 1; indexCol < noOfColumns; indexCol++){
                    matrix[indexRow][indexCol] = 0;
                }
            }
        }
        //Traverse for first row
        for(int indexCol = 1; indexCol < noOfColumns; indexCol++){
            if(matrix[0][indexCol] == 0){
                for(int indexRow = 1; indexRow < noOfRows; indexRow++){
                    matrix[indexRow][indexCol] = 0;
                }
            }
        }
        // if first row hold zero
        if(isFirstRowHoldZero){
            for(int indexCol = 0; indexCol < noOfColumns; indexCol++)
                matrix[0][indexCol] = 0;
        }
        // if first col hold zero
        if(isFirstColumnHoldZero){
            for(int indexRow = 0; indexRow < noOfRows; indexRow++)
                matrix[indexRow][0] = 0;
        }
    }
};
