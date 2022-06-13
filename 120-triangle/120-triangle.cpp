class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp;
        dp.push_back({triangle[0][0]});
        for(int i=1; i<n; i++){
            dp.push_back(vector<int>(i+1));
            for(int j=0; j<=i; j++){
                int Min = INT_MAX;
                if(j > 0)
                    Min = min(Min, dp[i-1][j-1]);
                if(j < i)
                    Min = min(Min, dp[i-1][j]);
                dp[i][j] = triangle[i][j] + Min;
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
