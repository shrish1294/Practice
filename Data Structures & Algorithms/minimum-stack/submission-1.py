class MinStack:

    def __init__(self):
        
        self.stack_1 = deque()
        self.stack_2 = deque()

    def push(self, val: int) -> None:
        self.stack_1.append(val)
        if len(self.stack_2) == 0 or self.stack_2[-1] >= val:
            self.stack_2.append(val)

    def pop(self) -> None:
        val = self.stack_1[-1]
        self.stack_1.pop()
        if len(self.stack_2) and self.stack_2[-1] == val:
            self.stack_2.pop()

    def top(self) -> int:
        return self.stack_1[-1]

    def getMin(self) -> int:
        return self.stack_2[-1]
        
