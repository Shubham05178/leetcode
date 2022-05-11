class Solution {
public:
    bool solver(int idx1, int  idx2, string &s, string &p, vector<vector<int>>& dp){
        if(idx1 == -1 && idx2 == -1)
            return true;
        if(idx1 == -1){
            while(idx2 >=0){
                if(p[idx2] != '*')
                    return false;
                idx2--;
            }
            return true;
        }
        if(idx2 == -1)
            return false;
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        if(p[idx2] == '?' || p[idx2] == s[idx1]) {
            dp[idx1][idx2] = solver(idx1 -1, idx2 - 1 ,s, p, dp);
        }
        else if(p[idx2]=='*'){
            dp[idx1][idx2] = solver(idx1 - 1, idx2, s, p, dp) || solver(idx1, idx2 - 1, s, p, dp);
        }
        else
            dp[idx1][idx2] = false;
        return dp[idx1][idx2];
        
    }
    bool isMatch(string s, string p) {
        int size1 = s.size();
        int size2 = p.size();
        vector<vector<int>>dp(size1, vector<int>(size2, -1));
        return solver(size1 - 1, size2 - 1, s, p, dp);
    }
};