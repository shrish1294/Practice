# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def fun(self, root):
        if not root or self.cnt >= k :
            return 
        if root.left:
            self.fun(root.left)
        self.cnt += 1
        if self.cnt == k and self.ans is None:
            self.ans = root.val
        if root.right and self.cnt < k:
            self.fun(root.right)

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.cnt = 0
        self.ans = None
        if not root:
            return -1
        
        self.fun(root)
        return self.ans