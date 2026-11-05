# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def is_good(self, root, maxi):
        if not root:
            return 
        if root.val >= maxi:
            self.cnt+=1
        # print(root.val, maxi)
        maxi = max(maxi, root.val)
        self.is_good(root.left, maxi)
        self.is_good(root.right, maxi)

    def goodNodes(self, root: TreeNode) -> int:
        self.cnt = 0
        self.is_good(root, -1e9)
        return self.cnt