# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    
    def dia(self, root: TreeNode) -> int:
        if not root:
            return 0
        x = self.dia(root.left)
        y = self.dia(root.right)
        self.maxi = max(self.maxi, x + y + 1)
        # print(self.maxi)
        return max(x, y) + 1

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        
        self.maxi = 0
        val = self.dia(root)
        return self.maxi - 1