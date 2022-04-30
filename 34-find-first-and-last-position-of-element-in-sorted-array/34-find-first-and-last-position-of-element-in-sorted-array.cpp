class Solution {
public: 
    int firstIndex(vector<int>& nums,int target) {
        int low = 0, high = nums.size() - 1, ans = -1, mid;
        while(low <= high) {
            mid = low + ((high - low) >> 1);
            if(nums[mid] == target) {
                ans = mid;
                high = mid - 1;
            }
            else if(nums[mid] > target)
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return ans;
    }
    int lastIndex(vector<int>& nums,int target) {
        int low = 0, high = nums.size() - 1, ans = -1, mid;
        while(low <= high) {
            mid = low + ((high - low) >> 1);
            if(nums[mid] == target) {
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid] > target)
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstIndex(nums, target), lastIndex(nums, target)};
    }
};