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

    int helper(TreeNode* root){
        if(!root)
            return 0;
        int h1 = helper(root->left);
        int h2 = helper(root->right);
        if(h1 == -1 || h2 == -1)
            return -1;
        if(abs(h1 - h2) > 1)
            return -1; 
        return 1 + max(h1, h2);
    }

    bool isBalanced(TreeNode* root) {
        
        int val = helper(root);
        if(val == -1)
            return false;
        return true; 
    }
};
