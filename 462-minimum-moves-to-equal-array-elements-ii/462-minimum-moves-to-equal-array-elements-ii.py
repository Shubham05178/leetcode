class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        size = len(nums)
        ans = 0
        for idx in range(size):
            ans += abs(nums[idx]- nums[size//2])
        return ans
        