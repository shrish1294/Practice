class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        
        v1 = [0]*26
        v2 = [0]*26

        if len(s2) < len(s1):
            return False

        n, m = len(s1), len(s2)
        for i in range(0, n):
            v1[ord(s1[i]) - 97] += 1
            v2[ord(s2[i]) - 97] += 1
        
        if v1 == v2:
            return True
        
        i = 0
        for j in range(n, m): 
            v2[ord(s2[i]) - 97] -= 1
            i+=1
            v2[ord(s2[j]) - 97] += 1
            if v1 == v2:
                return True
        
        return False
        