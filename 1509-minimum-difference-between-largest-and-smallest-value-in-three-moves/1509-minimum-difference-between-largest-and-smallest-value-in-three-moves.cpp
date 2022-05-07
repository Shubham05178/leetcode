class Solution {
public:
    int minDifference(vector<int>& nums) {
        int arrsize = nums.size();
        if(arrsize < 5) return 0;
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        for(int times = 0; times< 4; times++)
          mini = min( mini ,nums[arrsize - 4 + times]- nums[times]);
      return mini;
    }
};

// [1,5,0,10,14]
// [0,1,5,10,14] 
// [0,1,5]   [ 5, 10, 14]
//[6,6,0,1,1,4,6]
// [0,1,1,4,6,6,6]
          
