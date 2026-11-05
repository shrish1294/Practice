class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        n = len(nums)
        left_pr = [1] * n
        right_pr = [1] * n
        for i, j in enumerate(nums):
            left_pr[i] = left_pr[i-1] * j if i > 0 else j
        
        for i in range(n - 1, -1, -1):
            right_pr[i] = right_pr[i + 1] * nums[i] if i < n - 1 else nums[i]


        ans = []
        for i in range(0 , n):
            val = left_pr[i - 1] if i > 0 else 1
            val*= right_pr[i + 1] if i < n - 1 else 1
            ans.append(val)
        
        return ans
        