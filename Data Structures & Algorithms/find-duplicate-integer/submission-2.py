class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        
        n = len(nums)
        for i, j in enumerate(nums):
            nums[j % (n + 1)] += (n + 1)

        for i in range(1, n + 1):
            if nums[i] // (n + 1) > 1:
                return i
        return -1