/**
* Leetcode Problem - https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
* Author - Shubham Nagaria
* Date - 23rd April 2022
Removing Minimum and Maximum From Array
**/
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int  maxElementIndex= 0, minElementIndex =0;
        int numsSize = nums.size();
        for(int index =1; index < numsSize; index++){
            if(nums[index]>nums[maxElementIndex])
                maxElementIndex= index;
            if(nums[index]<nums[minElementIndex])
                minElementIndex = index;
        }
        int minIndex = min(maxElementIndex, minElementIndex);
        int maxIndex = max(maxElementIndex, minElementIndex);
       return min((numsSize-maxIndex) + minIndex+1 ,min(maxIndex+1, numsSize-minIndex));
    }
};