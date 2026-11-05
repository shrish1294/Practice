class Solution:
    def trap(self, height: List[int]) -> int:
        
        n = len(height)
        left = [0]*n
        right = [0] * n
        left_max = height[0]
        right_max = height[n - 1]
        for i in range(1, n):
            left_max = max(left_max, height[i])
            left[i] = left_max

        for i in range(n-2, -1, -1):
            right_max = max(right_max, height[i])
            right[i] = right_max
        
        ans = 0
        for i in range(0, n):
            mini = min(left[i], right[i])
            ans += max(0, mini - height[i])
        return ans