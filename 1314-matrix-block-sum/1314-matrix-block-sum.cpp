class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int nR = mat.size();
        int nC = mat[0].size();
        for(int idx = 1; idx < nR; idx++) {
            for(int idy= 0; idy <nC;idy++){
                mat[idx][idy]+= mat[idx-1][idy];
            }
        }
        for(int idy = 1; idy < nC; idy++) {
            for(int idx= 0; idx <nR;idx++){
                mat[idx][idy]+= mat[idx][idy -1];
            }
        }
        int mainx, mainy, topx, topy;
        vector<vector<int>>ans(nR, vector<int>(nC));
        for(int idx = 0;idx < nR; idx++){
            for(int idy = 0;idy < nC; idy++){
                mainx = idx + k; 
                mainy = idy + k;
                if(mainx >= nR) mainx = nR-1;
                if(mainy >=nC) mainy = nC-1;
                ans[idx][idy] = mat[mainx][mainy];
                topx = idx - k - 1;
                topy = idy - k - 1;
                if(topx < 0 && topy < 0)
                    continue;
                if(topx >= 0 && topy < 0)
                    ans[idx][idy] -= mat[topx][mainy];
                if(topx < 0 && topy >=0)
                    ans[idx][idy] -= mat[mainx][topy];
                if(topx >= 0 && topy >= 0){
                    ans[idx][idy] += (mat[topx][topy] - mat[topx][mainy] - mat[mainx][topy]);
                }
                
            }
        }
        return ans;
    }
};