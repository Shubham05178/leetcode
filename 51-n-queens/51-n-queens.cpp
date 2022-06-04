class Solution {
public:
    void NQueens(int index, int n, vector<vector<string>> &res, vector<string> &mat ,vector<int> &col, vector<int> &ld , vector<int> &rd){
        if(index == n){
            res.push_back(mat);
            return;
        }
        for(int j =0 ; j < n ; j++){
            if(col[j]==1 || rd[j+index]==1 || ld[n+j-index]==1)
                continue;
            mat[index][j]='Q';
            col[j]=1;
            ld[n+j-index]=1;
            rd[index+j]= 1;
            NQueens(index+1,n,res,mat,col,ld,rd);
            mat[index][j]='.';
            col[j]=0;
            ld[n+j-index]=0;
            rd[index+j]= 0;
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        string s="";
        for(int i =0 ; i <n ;i++)
            s+=".";
        vector<string>mat(n,s);
        vector<int>rd(2*n,0), ld(2*n,0),col(n,0);
        vector<vector<string>>res;
        NQueens(0,n,res,mat,col,ld,rd);
        return res;
    }
};