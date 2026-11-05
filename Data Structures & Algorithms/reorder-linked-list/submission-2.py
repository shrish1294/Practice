# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    @staticmethod
    def reverse(head: Optional[ListNode]) -> ListNode: 
        tmp = head
        prev = None
        if not head or not head.next:
            return head
        while tmp:
            nxt = tmp.next
            tmp.next = prev
            prev = tmp
            tmp = nxt
        return prev
    def reorderList(self, head: Optional[ListNode]) -> None:
        
        n = 0
        tmp = head
        while tmp:
            n +=1
            tmp = tmp.next
        if n <=2:
            return 
        
        n = n // 2
        tmp = head
        while tmp and n:
            n -= 1
            tmp = tmp.next
        right = tmp.next
        tmp.next = None
        right = self.reverse(right)

        tmp = head

        while tmp and right: 
            nxt = tmp.next
            tmp.next = right
            right = right.next
            tmp.next.next = nxt
           
            tmp = nxt
        

