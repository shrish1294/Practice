# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:

    @staticmethod
    def reverse(head: Optional[ListNode]) -> ListNode:
        if not head or not head.next:
            return head
        prev = None
        tmp = head
        while tmp:
            nxt = tmp.next
            tmp.next = prev
            prev = tmp
            tmp = nxt
        return prev

    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        
        new_head = self.reverse(head)
        if n == 1:
            prev = new_head
            new_head = new_head.next
            del prev
            return self.reverse(new_head)
        prev = new_head
        tmp = new_head
        while n and tmp:
            n-=1
            if n==0:
                prev.next = tmp.next
                # del tmp
                return self.reverse(new_head)
           
            prev = tmp
            tmp = tmp.next
           
        
        return None


        