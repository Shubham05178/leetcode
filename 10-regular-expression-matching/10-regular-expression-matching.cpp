class Solution {
public:
    bool solver(string &s , string& p, int ids, int idp, int size1, int size2, vector<vector<int>> &dp) {
        if(ids == size1 && idp == size2){
            return true;
        }
        if(ids==size1 && idp<size2){
            while(idp < size2){
                if(idp+1 >= size2 || p[idp+1] != '*')
                    return false;
                idp += 2;
            }
            return true;
        }
        if(idp >= size2)
            return false;
        if(dp[ids][idp] != -1)
            return dp[ids][idp];
        bool comp = (p[idp] == s[ids] || p[idp]=='.');
        if(idp + 1 < size2 && p[idp+1] =='*'){
        dp[ids][idp] = (solver (s, p, ids, idp + 2, size1, size2,dp) || (comp && solver (s, p, ids + 1, idp , size1, size2,dp)));
        }
        else{
          dp[ids][idp] = (comp && solver(s,p,ids +1,idp+1, size1,size2,dp));
        }
        return dp[ids][idp];
        
    }
    bool isMatch(string s, string p) {
        int size1 = s.size();
        int size2 = p.size();
        vector<vector<int>>dp(size1,vector<int>(size2,-1));
        return solver(s, p, 0, 0, size1, size2, dp);
    }
};