class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        map = {}
        for i in nums:
            if map.get(i):
                return True
            map[i] = 1

        return False
        
         