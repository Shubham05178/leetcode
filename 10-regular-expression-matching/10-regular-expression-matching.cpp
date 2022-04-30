class Solution {
public:
    bool isRegularExpression(int i, int j, int n, int m, string &s, string &p,vector<vector<int>> &dp){
        if(i >= n && j >= m)
            return true;
        if(j >= m)
            return false;
        if(i >= n){
            while(j < m){
                if(j+1 >= m || p[j + 1] != '*')
                    return false;
                j += 2;
            }
            return true;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        bool match = (s[i] == p[j] || p[j] == '.');
        if(j + 1 < m && p[j + 1] == '*') {
         dp[i][j] = isRegularExpression(i,j + 2, n, m, s, p, dp) || (match && isRegularExpression(i + 1, j, n, m, s, p, dp));
        }
        else{
            dp[i][j] = match && isRegularExpression(i+1,j+1,n,m,s,p,dp);    
        }
         return dp[i][j];   
    }
    bool isMatch(string s, string p) {
        int n =  s.size();
        int m = p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return isRegularExpression(0, 0, n, m, s, p, dp);
    }
};