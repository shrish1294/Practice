class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        

        stack = deque()
        for i in tokens:
            if i in ['+', '-', '/', '*']:
                v1 = int(stack[-1])
                stack.pop()
                v2 = int(stack[-1])
                stack.pop()
                if i == '+':
                    v1 += v2
                if i == '-':
                    v1 = v2 - v1
                if i == '*':
                    v1 *= v2
                if i == '/':
                    v1  = int(v2 / v1) if v1 != 0 else 0
                stack.append(v1)
            else:
                stack.append(int(i))
            # print(stack)
        
        return stack[-1]