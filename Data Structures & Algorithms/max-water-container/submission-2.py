class Solution:
    def maxArea(self, heights: List[int]) -> int:
        
        n = len(heights)
        l = 0
        r = n - 1
        
        ans = 0
        while l < r:
            val = min(heights[l], heights[r]) * (r - l)
            ans = max(ans, val)
            if heights[l] > heights[r]:
                r-=1
            else:
                l += 1
        
        return ans