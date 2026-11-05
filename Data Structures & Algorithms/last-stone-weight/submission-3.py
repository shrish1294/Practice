class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        
        heap = []

        for i in stones:
            heapq.heappush(heap, -i)
        
        while len(heap) > 1:
            s = heapq.heappop(heap)
            t = heapq.heappop(heap)
            val = t - s
            if val > 0:
                heapq.heappush(heap, -val)
        if len(heap):
            return abs(heap[0])
        return 0

       


        