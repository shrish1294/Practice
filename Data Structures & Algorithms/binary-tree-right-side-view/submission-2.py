# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
    
        q = deque()
        ans = []
        if not root:
            return ans
        q.append(root)
        while len(q):

            sz = len(q)
            it = q[-1]
            ans.append(it.val)
            while sz: 
                sz -= 1
                it = q.popleft()
                if it.left:
                    q.append(it.left)
                if it.right:
                    q.append(it.right)
        
        return ans
        
        