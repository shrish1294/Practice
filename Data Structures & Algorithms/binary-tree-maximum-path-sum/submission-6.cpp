/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int ans = INT_MIN;
    int helper(TreeNode* n){

        if(!n)
            return 0;
        
        int v1 = helper(n->left);
        int v2 = helper(n->right);

        int val = n->val;
         val = max(val, v1 + v2 + n->val);
     
        val = max(val, v1 + n->val);
       
        val = max(val, v2 + n->val);

        ans = max(ans, val);
      
        val = n->val;
      
        val = max(val, v1 + n->val);
       
        val = max(val, v2 + n->val);
        
        return val;

    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        ans = INT_MIN;
        helper(root);
        return ans;

    }
};
