# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def is_same(self, r1, r2) -> bool:
        if not r1 and not r2:
            return True
        if not r1 or not r2 or r1.val != r2.val:
            return False
        v1 =  self.is_same(r1.left, r2.left)
        if v1:
            return self.is_same(r1.right, r2.right)
        return v1        

    def fun(self, r1, r2):
        if not r1 and not r2:
            return True
        if not r1 or not r2:
            return False
        ans = False
        if r1.val == r2.val:
            ans = self.is_same(r1, r2)
        if ans:
            return ans
        return self.fun(r1.left, r2) | self.fun(r1.right, r2)


    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        
        return self.fun(root, subRoot)