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
    bool isSubtree(TreeNode* root, TreeNode* subRoot, bool match=false) {
        
        if(!root && !subRoot)
            return true;
        if(!root || !subRoot)
            return false;
        bool v1 = false;
        if(root->val == subRoot->val){
            v1 = isSubtree(root->left, subRoot->left, true);
            if(v1)
            v1 = isSubtree(root->right, subRoot->right, true);
        }
        
        if(v1)
            return true;
        if(match)
            return false;
        
        return isSubtree(root->left, subRoot) | isSubtree(root->right, subRoot);
        
    }
};
