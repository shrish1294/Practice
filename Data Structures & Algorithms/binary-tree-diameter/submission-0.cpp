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

    int ans = 0;
    int helper(TreeNode* root){
         if(!root)
            return 0;
        int v1 = helper(root->left);
        int v2 = helper(root->right);
        // cout<<v1<<" "<<v2<<" "<<root->val<<"\n";
        ans = max(ans, v1 + v2 + 1);
        return 1 + max(v1, v2); 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root)
            return 0;
        ans = 0;
        helper(root);
        return ans-1;
       
    }
};
