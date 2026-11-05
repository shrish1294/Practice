class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        

        q = deque()
        ans = []
        
        n = len(nums)
        for i in range(0, n):
            while len(q) > 0 and nums[i] > q[-1][0]:
                q.pop()
            q.append((nums[i], i))
            while len(q) and q[0][1] <= i - k:
                q.popleft()
            if i >= k-1:
                ans.append(max(q[0][0], q[-1][0]))
        return ans
