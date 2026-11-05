# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        
        if not list1:
            return list2
        if not list2:
            return list1
        
        prev, head = None, None
        if list1.val > list2.val: 
            head = list2
            list2 = list2.next
        else:
            head = list1
            list1 = list1.next
        prev = head
        prev.next = None
        while list1 and list2:
            if list1.val > list2.val:
                prev.next = list2
                list2 = list2.next
            else:
                prev.next = list1
                list1 = list1.next
            prev = prev.next
            prev.next = None


        
        if list2:
            prev.next = list2
        if list1:
            prev.next = list1
        
        return head