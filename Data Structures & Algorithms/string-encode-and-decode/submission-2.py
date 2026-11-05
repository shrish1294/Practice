class Solution:

    def encode(self, strs: List[str]) -> str:

        ans = ""
        for i in strs:
            n = len(i)
            l = len(str(n))

            ans = ans + str(l) + str(n) + i

        return ans

    def decode(self, s: str) -> List[str]:

        ans = []

        i = 0
        while i < len(s):
            num = int(s[i])
            i+=1
            str_len = int(s[i: i + num])
            st = s[i + num: i + num + str_len]
            ans.append(st)
            i = i + num + str_len

        return ans 