class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        arr = sorted(nums)
        n = len(arr)
        ans = set()
        
        for i in range(0, n-2):
            l = i + 1
            r = n-1
            while l < r:
                val = arr[l] + arr[r]
                if val == -arr[i]:
                    ans.add((arr[i], arr[l], arr[r]))
                if val < -arr[i]:
                    l += 1
                else:
                    r -= 1
        

        return list(ans)



        