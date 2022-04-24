class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        s = set(nums[0])
        for i in nums:
            s= s & set(i)
        return sorted(list(s))

        