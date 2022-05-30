class Solution {
public:
    bool nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int idx = size - 2;
        while(idx >= 0 && nums[idx + 1] <= nums[idx] )
            idx--;
        if(idx >= 0){
            int idy = size - 1, maxi = INT_MAX;
            int mini = idy;
            while(idy > idx){
                if( nums[idy] - nums[idx] > 0 && nums[idy] - nums[idx] < maxi){
                    maxi = nums[idy] - nums[idx];
                    mini = idy;
                }
                idy--;
            }
            swap(nums[idx],nums[mini]);
            reverse(nums.begin()+idx+1 , nums.end());
        }
        else
            return false;
        return true;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
       vector<vector<int>>ans;
        do {
            ans.push_back(nums);
        }while(nextPermutation(nums));
        return ans;
    }
};