class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size() - 1;
        int high = n, low = 0 , mid;
        while(low <= high) {
            mid = low + ((high - low) >> 1);
            if((mid == n || nums[mid] > nums[mid + 1] ) && (mid == 0 || nums[mid] > nums[mid - 1]))
                return mid;
            else if( mid != n && nums[mid] < nums[mid + 1])
                low = mid + 1;
            else
                high = mid-1;    
        }
    return -1;
    }
};