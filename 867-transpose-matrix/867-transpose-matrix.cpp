class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>>transposed(cols, vector<int>(rows));
        for(int idx = 0; idx < rows; ++idx ) {
            for(int idy = 0; idy < cols; ++idy) {
                transposed[idy][idx] = matrix[idx][idy];
            }
        }
        return transposed;
    }
};