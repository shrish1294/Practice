# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def fun(self, root):
        if not root or not self.check:
            return 0
        x = self.fun(root.left)
        y = self.fun(root.right)
        if abs( x - y) > 1:
            self.check = False
        return max(x, y) + 1

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        
        self.check = True
        if not root:
            return True
        
        self.fun(root)
        return self.check
        
    