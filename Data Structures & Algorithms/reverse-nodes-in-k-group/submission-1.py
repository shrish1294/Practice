# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:

    @staticmethod
    def reverse(head):
        if not head or not head.next: 
            return head, head
        
        tmp = head
        prev = None
        while tmp:
            nxt = tmp.next
            tmp.next = prev
            prev = tmp
            tmp = nxt
        return prev, head

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next or k <= 1:
            return head
        tmp = head
        old_tail = None 
        new_head = None
        while tmp:
            cnt = 0
            st = tmp
            while tmp and cnt < k - 1: 
                cnt += 1
                tmp = tmp.next
            nxt = tmp.next if tmp else None
            if cnt == k-1 and tmp:
                # if tmp:
                tmp.next = None                
                hd, tail = self.reverse(st)
                print(hd.val, tail.val)
                if not new_head:
                    new_head = hd
                if old_tail:
                    old_tail.next = hd
                old_tail = tail
            else:
                if old_tail:
                    old_tail.next = st
            tmp = nxt
            # if tmp:
            #     print(tmp.val)
        return new_head if new_head else head

