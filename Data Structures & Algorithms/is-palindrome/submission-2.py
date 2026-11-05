import re
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = re.sub(r'[^a-zA-z0-9]', "", s)
        s = s.lower()
        r = s[::-1]
        return r == s