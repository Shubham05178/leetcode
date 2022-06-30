class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        m = 0
        dp = [0 for _ in range(n)]
        for i in range(1, len(nums)):
            dp[i] = (nums[i] - nums[i-1])* i + dp[i-1]
        ans = dp[n-1]
        for i in range(len(nums)-2,-1,-1):
            m += (nums[i + 1] - nums[ i ]) * (n - 1 - i)
            ans = min(ans, m + dp[i])
        return ans
        