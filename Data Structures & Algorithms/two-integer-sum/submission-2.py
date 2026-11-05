class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        mapper = {}
        for i, j in enumerate(nums):
            if mapper.get(target - j) is not None:
                return [mapper[target - j], i]
            mapper[j] = i
        
        
        return []
        