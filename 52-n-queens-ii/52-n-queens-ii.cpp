
class Solution {
public:
    void CountToatlNQueens(int i, int n, int &count, vector<vector<int>> &mat, vector<int> &col, vector<int> &ld, vector<int> &rd){
        if(i == n ){
            count++;
            return;
        }
        for(int j =0 ; j < n; j++){
            if(col[j]==1 || ld[n+j-i]==1 || rd[i+j]==1)
                continue;
            mat[i][j] = 1;
            col[j] = 1;
            ld[n+j-i] = 1;
            rd[i+j]= 1;
            CountToatlNQueens(i+1,n,count,mat,col,ld,rd);
             mat[i][j] = 0;
            col[j] = 0;
            ld[n+j-i] = 0;
            rd[i+j] = 0;
        }
        return;
    }
    int totalNQueens(int n) {
        vector<vector<int>>mat(n,vector<int>(n,0));
        vector<int>col(n,0), ld(2*n,0),rd(2*n,0);
        int count=0;
        CountToatlNQueens(0,n,count,mat,col,ld,rd);
        return count;
    }
};