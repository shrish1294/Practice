# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def fun(self, root):
        if not root:
            return 0
        
        v1 = self.fun(root.left)
        v2 = self.fun(root.right)
        self.ans = max(self.ans , v1 + v2 + root.val)
        return max(v1 + root.val, v2 + root.val, root.val, 0)

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        
        self.ans = -1e9

        self.fun(root)
        return self.ans
