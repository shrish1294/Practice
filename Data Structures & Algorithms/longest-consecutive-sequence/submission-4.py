class Solution:

    def check(self, visited, i, cntr, mapper):
        if not mapper[i] :
            return 0
        if i in visited:
            return cntr[i]
        visited.add(i)
        cntr[i] = 1 + self.check(visited, i - 1, cntr, mapper)
        return cntr[i]

    def longestConsecutive(self, nums: List[int]) -> int:

        if len(nums) <= 1:
            return len(nums)
      

        mapper = defaultdict(int)
        for i in nums:
            mapper[i] = 1
        
        visited = set()
        cntr = defaultdict(int)
        
        for i in nums:
            if i in visited:
                continue
            self.check(visited, i, cntr, mapper)
        
        ans = 1
        for k, v in cntr.items():
            ans = max(ans, v)
        return ans

            
        