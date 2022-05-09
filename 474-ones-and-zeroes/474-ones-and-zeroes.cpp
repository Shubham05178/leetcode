class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[n + 1][m + 1], x, y;
        memset(dp, 0, sizeof(dp));
        for(string &s : strs) {
            x = count(s.begin(), s.end(), '1');
            y = s.size() - x;
            for(int idx = n; idx >= x; idx--){
                for(int idy = m; idy >= y; idy--)
                    dp[idx][idy] = max(dp[idx][idy], 1 + dp[idx - x][idy - y]);
            }
        }
        return dp[n][m];
    }
};