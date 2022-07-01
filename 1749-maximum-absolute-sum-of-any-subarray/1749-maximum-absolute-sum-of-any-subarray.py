class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        currSum1, maxSum1, currSum2, maxSum2 = 0, 0, 0, 0
        for num in nums:
            currSum1 += num
            currSum2 -= num
            if currSum1 < 0:
                currSum1 = 0
            maxSum1 = max(maxSum1, currSum1)
            if currSum2 < 0:
                currSum2 = 0
            maxSum2 = max(maxSum2, currSum2)
        return max(maxSum1, maxSum2)
                   
            
        