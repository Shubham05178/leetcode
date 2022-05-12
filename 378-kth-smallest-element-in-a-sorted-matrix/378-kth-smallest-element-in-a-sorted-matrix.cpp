class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>>pq;
        int rowS = matrix.size();
        int colS = matrix[0].size();
        for(int idx = 0; idx < rowS && idx < k;idx++)
            pq.push({-matrix[idx][0], idx, 0});
        int ans, idx,idy;
        while(k--){
            auto top = pq.top();
            pq.pop();
            ans = -top[0];
            idx = top[1];
            idy = top[2];
            if(idy + 1 < colS)
                pq.push({-matrix[idx][idy+1], idx, idy + 1});
        }
        return ans;
    }
};