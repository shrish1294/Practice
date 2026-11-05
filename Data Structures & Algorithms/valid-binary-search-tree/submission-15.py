# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def fun(self, root):
        if not root:
            return 0, 0
        x, y = root.val, root.val
        if root.left:
            a, b = self.fun(root.left)
            if x <= b:
                self.ans = False
            x = min(x, a)
            y = max(y, b)
        if root.right:
            a, b = self.fun(root.right)
            if a <= y:
                self.ans = False
            x = min(a, x)
            y = max(b, y)
        return x, y
        

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        self.ans = True
        self.fun(root)
        return self.ans