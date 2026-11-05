class Solution:


    def search(self, nums: List[int], target: int) -> int:
        
        m = len(nums)
        l = 0
        r = m-1
        while l<=r:
            mid = int((l + r) / 2)
            if nums[mid] > target:
                r = mid - 1
            elif nums[mid] == target:
                return mid
            else:
                l = mid + 1
        
        return -1

