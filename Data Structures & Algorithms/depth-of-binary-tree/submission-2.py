# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def depth(self, root: TreeNode) -> int: 
        if not root: 
            return 0
        x = self.depth(root.left)
        y = self.depth(root.right)
        return max(x, y) + 1

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        
        return self.depth(root)