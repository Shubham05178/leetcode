class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>>p(n, vector<bool>(n, false));
        vector<int>dp(n,INT_MAX);
        for(int diff = 0; diff < n; ++diff) {
            for(int i = 0, j = diff; j < n && i < n ; i++, j++){
                if(i== j){
                    p[i][j]=true;
                }
                else if(j - i == 1){
                    if(s[i]==s[j])
                        p[i][j]=true;
                }
                else{
                    if(s[i]==s[j])
                        p[i][j]= true;
                    p[i][j]= p[i][j]&& p[i+1][j-1];
                }
            }
        }
      dp[0]=0;
        for(int j = 0; j < n; j++){
            if(p[0][j]) dp[j] =0;
            else{
                for(int i = 1; i <= j;i++){
                    if(p[i][j])
                        dp[j]= min(dp[j], 1+ dp[i-1]);
                }
            }
        }
        return dp[n-1];
    }
};