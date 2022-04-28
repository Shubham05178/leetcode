// Problem Statement - https://leetcode.com/problems/pascals-triangle
// Problem - Pascal's Triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //creating vector for final result
        vector<vector<int>> result;
        //creating vector for storing intermediate results
        vector<int> intermediateResult;
        //iterating over each row till we reach numRows
        for(int row = 0; row < numRows; row++) {
            intermediateResult.push_back(1);
            //calculating sum of above row elements at index same column and one reduced column
            for(int idx = 1; idx < row; idx++) {
                intermediateResult.push_back(result[row - 1][idx] + result[row - 1][idx - 1]);
            }
            if(row > 0){
                intermediateResult.push_back(1);
            }
            //pushing intermediate results in result
            result.push_back(intermediateResult);
            //clearing intermediate result for next iteration
            intermediateResult.clear();
        }
        //returning result
        return result;
    }
};