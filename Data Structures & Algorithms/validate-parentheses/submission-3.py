class Solution:
    def isValid(self, s: str) -> bool:
        
        stack = deque()

        for i in s: 
            if i in ['(', '[', '{']:
                stack.append(i)
            elif len(stack) == 0:
                return False
            else:
                if i == '}' and stack[-1] != '{':
                    return False
                if i == ')' and stack[-1] != "(":
                    return False
                
                if i == ']' and stack[-1] != '[':
                    return False
                stack.pop()
        
        return False if len(stack) else True
