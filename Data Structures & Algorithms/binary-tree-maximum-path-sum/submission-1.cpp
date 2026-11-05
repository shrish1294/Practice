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
    int ans ;
    int fun(TreeNode* root){
        if(!root)
            return 0;
        int v1 = fun(root->left);
        int v2 = fun(root->right);
        ans = max(ans, v1 + root->val);
        ans = max(ans, v2 + root->val);
        ans = max(ans, root->val);
        ans = max(ans, v1 + v2 + root->val);
        int k = max(v1 + v2 + root->val, root->val);
        return max(root->val, max(v1+root->val, v2+root->val));
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        fun(root);
        return ans; 
    }
};
