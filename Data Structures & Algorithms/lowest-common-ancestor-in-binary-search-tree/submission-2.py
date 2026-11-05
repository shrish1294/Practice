# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def fun(self, root, p, q): 
        if not root:
            return False, False
        f_p, f_q = False, False
        if root.val == p.val:
            f_p = True
        if root.val == q.val: 
            f_q = True
        x, y = self.fun(root.left, p, q)
        f_p |= x
        f_q |= y
        x, y = self.fun(root.right, p, q)
        f_p |= x
        f_q |= y
        if f_p and f_q and self.ans is None:
            self.ans = root
        return f_p, f_q


    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        
        self.found_p = False
        self.found_q = False
        self.ans = None

        self.fun(root, p, q)
        return self.ans 