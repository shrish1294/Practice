# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        
        heap = []

        cnt = 0
        for a in lists:
            if a is not None:
                cnt +=1
                heapq.heappush(heap, (a.val, cnt, a))
        tmp = None
        head = None
        while len(heap):
            it = heapq.heappop(heap)
            if it[-1].next:
                cnt+=1
                heapq.heappush(heap, (it[-1].next.val,cnt, it[-1].next))
            if not head:
                head = it[-1]
                tmp = head
            else:
                tmp.next = it[-1]
                tmp = tmp.next
        
        
        return head