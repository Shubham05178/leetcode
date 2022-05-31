class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<vector<int>>difficultyprofit;
        int n = profit.size();
        for(int idx= 0; idx < n; idx++)
            difficultyprofit.push_back({difficulty[idx], profit[idx]});
        sort(difficultyprofit.begin(), difficultyprofit.end());
        int m = 0; 
        for(int idx = 0; idx<n; idx++){
            m = max(m, difficultyprofit[idx][1]);
            difficultyprofit[idx][1] = m;
        }
        sort(difficulty.begin(), difficulty.end());
        int res = 0;
        for(int w : worker){
            int idx = upper_bound(difficulty.begin(), difficulty.end(), w) - difficulty.begin() - 1;
            if(idx < 0) continue;
            res += difficultyprofit[idx][1];
        }
        return res;
    }
};