class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        

        heap = []
        for i in points:
            dist = math.sqrt(i[0]**2 + i[1]**2)
            heapq.heappush(heap, (dist, i))
        
        ans = []
        while k > 0:
            k-=1
            it = heapq.heappop(heap)
            ans.append(it[1])
        
        return ans
            