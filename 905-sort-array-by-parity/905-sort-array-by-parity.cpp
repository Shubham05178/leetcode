class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
      int i = 0, j = nums.size() - 1;
      while(i < j) {
        while(i < j && nums[i] % 2 == 0) 
          i++;
        while(j > i && nums[j] % 2 == 1)
          j--;
      if(nums[i] % 2 == 1 && nums[j] % 2 == 0)
        swap(nums[i], nums[j]);
      }
      return nums;
    }
};