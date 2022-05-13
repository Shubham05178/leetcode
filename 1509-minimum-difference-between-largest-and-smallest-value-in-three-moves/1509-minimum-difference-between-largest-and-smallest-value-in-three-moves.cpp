class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n < 5) return 0;
        partial_sort(nums.begin(), nums.begin() + 4, nums.end());
        nth_element(nums.begin() + 4, nums.end() - 4, nums.end());
        sort(nums.end()-4, nums.end());
        int mini = INT_MAX;
        for(int idx = 0; idx <4; idx++){
            mini = min(mini, nums[nums.size()-4 + idx]- nums[idx]);
        }
        return mini;
    }
};