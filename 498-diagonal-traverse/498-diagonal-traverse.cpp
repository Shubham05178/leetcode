class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int idx = 0, idy = 0, dir = 1;
        int nR = mat.size(), nC = mat[0].size();
        int dis[2] = {1,-1};
        while(idx < nR && idy < nC){
            dir = (1 ^ dir);
            while(idx >= 0 && idy >= 0 && idx < nR && idy < nC){
                ans.push_back(mat[idx][idy]);
                idx += dis[1 ^ dir];
                idy += dis[dir];
            } 
            if(idy == nC){
                idy--;
                idx +=2;
            }
            else if(idx == nR){
                idy +=2;
                idx--;
            }
            else if(idx < 0)
                idx++;
            else if(idy < 0)
                idy++;
        }
        return ans;
    }
};