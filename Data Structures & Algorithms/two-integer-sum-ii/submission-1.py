class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:

        n = len(numbers)
        left = 0
        right = n - 1

        while left < right:
            val = numbers[left] + numbers[right]
            if val == target:
                return [left + 1, right + 1]
            if val < target: 
                left += 1
            else:
                right -= 1

        return []
        