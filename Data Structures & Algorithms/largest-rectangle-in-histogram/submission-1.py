class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        
        n = len(heights)
        
        left_val = [0]*(n + 1)
        right_val = [0]*(n + 1)

        stack = deque()
        for i in range(0, n):
            if len(stack) == 0 :
                stack.append((heights[i], i))
            else:
                while len(stack) and stack[-1][0] > heights[i]:
                    val = stack[-1]
                    left_val[val[1]] = (i - val[1])
                    stack.pop()
                stack.append((heights[i], i))
        
        last = n
        while len(stack):
            val = stack[-1]
            stack.pop()
            left_val[val[1]] = left_val[last] + (last - val[1])
            last = val[1]
        
         
        for i in range(n-1, -1, -1):
            if len(stack) == 0 :
                stack.append((heights[i], i))
            else:
                while len(stack) and stack[-1][0] > heights[i]:
                    val = stack[-1]
                    right_val[val[1]] = abs(i - val[1])
                    stack.pop()
                stack.append((heights[i], i))
        last = -1
        while len(stack):
            val = stack[-1]
            stack.pop()
            if last != -1:
                right_val[val[1]] = right_val[last] + abs(last - val[1])
            else:
                right_val[val[1]] = 1
            last = val[1]
        ans = 0
        print(left_val)
        print(right_val)

        for i in range(0, n):
            val = left_val[i] + right_val[i] - 1
            ans = max(ans, val * heights[i])
        return ans

