class Solution:


    def check(self, n1, n2, ans):
       
        if n1 == n2 and n1 == 0:
            br = ''.join(ans)
            print(ans)
            return self.st.add(br)
      
        if n1 != 0: 
            ans.append('(')
            self.check(n1 - 1, n2, ans)
            ans.pop()
        if n2 != 0 and n1 < n2:
            ans.append(')')
            self.check(n1, n2 - 1, ans)
            ans.pop()
        
        

    def generateParenthesis(self, n: int) -> List[str]:
        
        self.st = set()
        ans = []
        self.check(n, n, ans)
        return list(self.st)

