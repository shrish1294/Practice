class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:

        mapper = {}
        for i in nums:
            if mapper.get(i):
                return True
            mapper[i] = True
        
        return False

        