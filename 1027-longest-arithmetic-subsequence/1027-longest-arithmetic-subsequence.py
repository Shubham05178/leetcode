class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        dp = {}
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                dp[j, nums[i] - nums[j]] = dp.get((i, nums[i]-nums[j]), 1) + 1
        return max(dp.values())
            
            
        