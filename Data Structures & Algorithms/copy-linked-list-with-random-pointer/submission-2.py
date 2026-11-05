"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return head
        head2 = Node(head.val)
        mapper = defaultdict()
        mapper[head] = head2
        tmp1 = head.next
        tmp2 = head2
        while tmp1:
            n = Node(tmp1.val)
            tmp2.next = n
            tmp2 = n
            mapper[tmp1] = n
            tmp1 = tmp1.next

        tmp1 = head
        tmp2 = head2
        while tmp1:
            if tmp1.random: 
                r = mapper[tmp1.random]
                tmp2.random = r
            tmp1 = tmp1.next
            tmp2 = tmp2.next
        
        return head2
            