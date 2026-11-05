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
    bool isTree(TreeNode* root , TreeNode* sub){
        if(!root && !sub)
            return true;
        if(!root || !sub)
            return false;
        if(root->val != sub->val)
            return false;
        return isTree(root->left, sub->left) & 
            isTree(root->right, sub->right);
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)
            return true;
        if(!root || !subRoot)
            return false;
        bool ans = true;
        if(root->val == subRoot->val){
            ans = isTree(root->left,  subRoot->left) & 
            isTree(root->right,  subRoot->right);
            if(ans)
                return ans;
        }
        return isSubtree(root->left,  subRoot) | 
        isSubtree(root->right,  subRoot);

        
    }
};
