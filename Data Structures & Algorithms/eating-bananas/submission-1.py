class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        

        l, r = 1, 1e9
        ans = 1e9
        while l <= r:
            mid = (l + r) // 2
            cnt = 0
            for a in piles:
                cnt += (a + mid - 1) // mid
                
            
            if cnt <= h:
                ans = min(mid, ans)
                r = mid - 1
            else:
                l = mid + 1
        
        return int(ans)