# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def check(self, root):
        if not root:
            return None
        if root.left:
            self.check(root.left)
        if root.right:
            self.check(root.right)
        tmp = root.left
        root.left = root.right
        root.right = tmp
        return root

    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        
        return self.check(root)