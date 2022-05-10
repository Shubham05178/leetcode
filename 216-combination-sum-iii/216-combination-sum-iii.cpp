class Solution {
public:
    vector<vector<int>>res;
    void Solver(int idx, vector<int>&combination, int sum, int k, int n) {
        if(k == 0 && sum == n) {
            res.push_back(combination);
            return;
        }
        if( k == 0 || sum > n)
            return;
        for(int idy = idx; idy <= 9; idy++ ){
            sum += idy;
            combination.push_back(idy);
            Solver(idy + 1, combination, sum, k - 1, n);
            combination.pop_back();
            sum -= idy;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>combination;
        Solver(1, combination, 0, k, n);
        return res;
    }
};