class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0 , size = nums.size();
        for(int idx = 0; idx < k; idx++)
            sum += nums[idx];
        double mx = sum/k;
        for(int idx = k; idx < size; idx++){
            sum += (nums[idx] - nums[idx - k]);
            mx = max(mx, sum/k);
        }
        return mx;
    }
};