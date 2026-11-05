class Solution:

   

    def findMin(self, nums: List[int]) -> int:

        n = len(nums)
        
        if nums[0] <= nums[-1]:
            return nums[0]
        
        l, r = 1, n - 1

        while l <= r: 
            mid = (l + r) // 2
            if nums[mid] < nums[mid -1]: 
                return nums[mid]
            if nums[mid] > nums[-1]:
                l = mid + 1
            else:
                r = mid - 1
        
        return -1