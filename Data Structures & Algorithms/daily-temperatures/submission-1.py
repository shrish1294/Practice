class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        
        stack = deque()
    
        n = len(temperatures)
        ans = [0]*n

        for i in range(0, n):

            if len(stack) == 0 or stack[-1][0] >= temperatures[i]:
                stack.append((temperatures[i], i))

            else:
                while len(stack) and stack[-1][0] < temperatures[i]:
                    ans[stack[-1][1]] = i - stack[-1][1]
                    stack.pop()
                stack.append((temperatures[i], i))

        return ans