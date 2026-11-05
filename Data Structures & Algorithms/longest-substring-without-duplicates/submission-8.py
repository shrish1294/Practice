class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        n = len(s)
        arr = defaultdict(int)
        l = 0
        r = 0
        ans = 0
        while r < n: 
            asci = ord(s[r])
            if arr[asci - 97] == 0:
                arr[asci - 97] = 1
                r+=1
            else:
                while l < r and arr[asci - 97] == 1:
                    arr[ord(s[l]) - 97] = 0
                    l+=1
                arr[asci - 97] = 1
                r+=1
            ans = max(ans, r - l)
        
        return ans