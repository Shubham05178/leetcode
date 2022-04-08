class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    void traverse (vector<vector<int>>& matrix,vector<vector<int>>& dp,int i,int j,int& maxi, int dis){
        maxi=max(maxi,dis);
        dp[i][j]=dis;
        for(int l =0; l < 4;l++){
            int xa = i+dx[l];
            int ya = j+dy[l];
             if(xa >=0 && ya >= 0 && xa<matrix.size() && ya<matrix[0].size() && matrix[i][j]<matrix[xa][ya] && dis+1 > dp[xa][ya]){
                 traverse(matrix,dp,xa,ya,maxi,dis+1);
            }
        }
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix[0].size(), n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        int maxi=0;
        int dis=1;
        for(int i = 0 ; i < n; i++){
            for(int j =0; j < m ; j++){
                if(dp[i][j]==-1)
                traverse(matrix,dp,i,j,maxi,dis);
            }
        }
        return maxi;
    }
};