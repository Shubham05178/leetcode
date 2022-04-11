class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), mini = INT_MAX, maxi= INT_MIN;
        int dp1[n],dp2[n];
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        for(int i = 0; i < n ;i++){
            mini = min(mini, prices[i]);
            if(i>0)
                dp1[i]= max(dp1[i-1],prices[i]-mini);
        }
        for(int i = n-1; i>=0; i--){
            maxi = max(maxi,prices[i]);
            if(i<n-1)
                dp2[i]= max(dp2[i],maxi- prices[i]);
        }
        int m =0;
        for(int i =0; i < n;i++)
            m = max(m, dp1[i]+dp2[i]);
        return m;
    }
};