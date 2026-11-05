class Solution:
    def characterReplacement(self, s: str, k: int) -> int:

        n = len(s)
        ans = 0
        K = k

        for i in range(0, 26):
            char = chr(ord('A') + i)
            l = 0
            r = 0
            k = K
            while r < n: 
                if s[r] == char:
                    r+=1
                elif k > 0:
                    r+=1
                    k-=1
                else:
                    while s[l] == char and l < r:
                        l+=1
                    l+=1
                    r += 1
                ans = max(ans, r - l)
    
        return ans
                
        