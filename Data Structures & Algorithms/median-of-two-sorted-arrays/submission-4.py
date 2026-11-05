class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        m, n = len(nums1), len(nums2)
        if m > n:
            return self.findMedianSortedArrays(nums2, nums1)

        l, r = 0, m
        median = (m + n - 1) // 2

        while l <=r:
            mid = (l + r )// 2 
            rest = median - mid
            l1 = nums1[mid - 1] if mid - 1 >= 0 else -1e9
            r1 = nums1[mid] if mid < m else 1e9
            l2 = nums2[rest - 1] if rest - 1 >= 0 else -1e9
            r2 = nums2[rest] if rest < n else 1e9

            if r1 >= l2 and r2 >= l1:
                if((m + n)  & 1):
                    return min(r2, r1)
                else:
                    m1 = nums1[mid + 1] if mid + 1 < m else 1e9
                    m2 = nums2[rest + 1] if rest + 1 < n else 1e9
                    a = [m1, m2, r1, r2]
                    a = sorted(a)
                    return (a[0] + a[1]) / 2
            elif r1 < l2:
                l = mid + 1
            else:
                r = mid - 1

        return -1
            


#  [ | ---] -> l1 , r1
#  [-- | --] -> l2, r2

# ideally -> r1 > l2, and r2 > l1
#  if r1 < l2 -> move right
#  if r2 < l1 -> move left
