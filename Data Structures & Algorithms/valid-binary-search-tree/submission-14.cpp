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

    bool helper(TreeNode* n, int &val){
        if(!n)
            return true;
        
        if(!helper(n->left, val))
            return false;
        if(val >= n->val)
            return false;
        val = n->val;

        return helper(n->right, val);
    }

    bool isValidBST(TreeNode* root) {
        
        int val = INT_MIN;
    

        return helper(root, val);
    }
};
