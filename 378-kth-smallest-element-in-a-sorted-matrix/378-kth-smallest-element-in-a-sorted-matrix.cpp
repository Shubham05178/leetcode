class Solution {
public:
    int countLessOREqual(vector<vector<int>> &matrix, int x, int rS, int cS) {
        int count = 0, idy = cS;
        for(int idx = 0; idx <= rS; idx++){
            while(idy >= 0 && x < matrix[idx][idy]) idy--;
            count += (idy + 1);
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rS = matrix.size()- 1, cS = matrix[0].size() - 1;
        int low = matrix[0][0], high = matrix[rS][cS], mid, ans;
        while(low <= high){
            mid = low + ((high - low) >> 1);
            if(countLessOREqual(matrix,mid,rS, cS) >= k){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};