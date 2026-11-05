class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        mapper = defaultdict(int)
        
        for n in nums:
            mapper[n] += 1
        
        heap = []
        for i, j in mapper.items():
            heapq.heappush(heap, (j, i))

            if len(heap) > k:
                heapq.heappop(heap)
        
        return [i[1] for i in heap]