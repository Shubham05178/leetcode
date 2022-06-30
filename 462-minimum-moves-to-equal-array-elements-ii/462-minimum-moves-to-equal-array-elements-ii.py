class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        size = len(nums)
        noofmovesfromrighttoleft = 0
        dp = [0 for _ in range(size)]
        for idx in range(1, size):
            dp[idx] = (nums[idx] - nums[idx - 1]) *  idx + dp[idx - 1]
        ans = dp[size - 1]
        for idx in range(size - 2, -1, -1):
            noofmovesfromrighttoleft += (nums[idx + 1] - nums[idx]) * (size - 1 - idx)
            ans = min(ans, noofmovesfromrighttoleft + dp[idx])
        return ans
        