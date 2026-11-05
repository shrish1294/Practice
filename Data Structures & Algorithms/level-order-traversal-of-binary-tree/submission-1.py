# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []

        q = deque()
        if not root:
            return ans
        q.append(root)
        
        while len(q):
            sz = len(q)
            tmp = []
            while sz:
                sz-=1
                it = q.popleft()
                if it.left:
                    q.append(it.left)
                if it.right:
                    q.append(it.right)
                tmp.append(it.val)
            ans.append(tmp)

        return ans
