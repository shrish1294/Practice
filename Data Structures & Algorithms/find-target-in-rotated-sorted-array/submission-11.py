class Solution:
    @staticmethod
    def get_pivot( nums: List[int], l: int, r: int) -> int:
        
        if nums[l] <= nums[r]:
            return r

        l = min(1, l)
        while l<=r:
            mid = (l + r) // 2
            if nums[mid] < nums[mid - 1]:
                return mid
            if nums[mid] > nums[-1]:
                l = mid + 1
            else:
                r = mid - 1
        
        return l
    @staticmethod
    def _search(nums: List[int], l: int, r: int, target: int) -> int:
        
        while l <=r :
            mid = (l + r) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] > target: 
                r = mid - 1
            else:
                l = mid + 1
        return -1

    def search(self, nums: List[int], target: int) -> int:

        l, r = 0, len(nums)
        if nums[l] <= nums[r-1]:
            return self._search(nums, 0, r - 1, target)


        pivot = self.get_pivot(nums, l, r - 1)
        print(pivot)
        if r == 1:
            return 0 if (target == nums[-1]) else -1

        if target > nums[-1]:
            return self._search(nums, 0, pivot - 1, target)
        return self._search(nums, pivot, r - 1, target)
