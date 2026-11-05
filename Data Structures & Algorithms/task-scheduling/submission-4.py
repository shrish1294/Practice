class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        
      

        mapper = defaultdict(int)
        m = len(tasks)
        for  i in tasks:
            mapper[i] += 1
           
        arr = []
                
        
        heap = []
        for i, j in mapper.items():
            arr.append([j, i])
        arr = sorted(arr, reverse=True)
        m = len(arr)
       
        i = 1
        heapq.heappush(heap, (0, -arr[0][0]))
        curr_time = 0
        print(arr)

        while len(heap) or i < m:
            if len(heap) == 0 and i < m:    
                heapq.heappush(heap, (curr_time, -arr[i][0]))
                i += 1
                continue
            if i < m and -arr[i][0] < heap[0][1]:
                heapq.heappush(heap, (curr_time, -arr[i][0]))
                i += 1
                continue

            it = heapq.heappop(heap)
            v1, v2 = it[0], it[1]
            if v1 <= curr_time:
                v1 = curr_time + n + 1
                v2 += 1
                if v2 < 0:
                    heapq.heappush(heap, (v1, v2))
            else:
                if i < m: 
                    if arr[i][0] - 1 > 0: 
                        heapq.heappush(heap, (curr_time + n + 1, -(arr[i][0] - 1)))
                    i += 1
                    heapq.heappush(heap, (v1, v2))
                else:
                    v2 += 1
                    curr_time = v1
                    v1 += n + 1
                    if v2 < 0: 
                        heapq.heappush(heap, (v1, v2))
            curr_time += 1

        return curr_time

        
