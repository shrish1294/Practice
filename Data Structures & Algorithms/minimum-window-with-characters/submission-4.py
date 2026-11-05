class Solution:

    def check(self, arr1, arr2):
        
        for k, v in arr1.items():
            if arr2[k] < v:
                return False
        return True


    def minWindow(self, s: str, t: str) -> str:
        
        m, n = len(s), len(t)
        if n > m:
            return ""
        
        arr1 = defaultdict(int)
        arr2 = defaultdict(int)
        for i in t:
            arr1[i] += 1
        i = 0
        j = 0
        ans = m
        ans_str = ""
        while j < m:
            arr2[s[j]] += 1
            j += 1
            while i < j and self.check(arr1, arr2):
                if ans >= j - i: 
                    ans = j - i
                    ans_str = s[i:j]

                arr2[s[i]] -= 1
                i+=1

        return ans_str
