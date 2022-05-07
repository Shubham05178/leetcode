class Solution {
public:
    int minDifference(vector<int>& nums) {
        int arrsize = nums.size();
        if(arrsize < 5) return 0;
        partial_sort(nums.begin(), nums.begin() + 4, nums.end());
        nth_element(nums.begin() + 4, nums.end() - 4, nums.end());
        sort(nums.end()-4 , nums.end());
        int minDiff = INT_MAX;
        for(int times = 0; times < 4; times++)
          minDiff = min(minDiff, nums[arrsize - 4 + times] - nums[times]);
      return minDiff;
    }
};
