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
    void helper(TreeNode* n, int &k){
        if(!n || k  == 0)
            return ; 
        helper(n->left, k);
        k-=1;
        if(k == 0)
            ans = n->val;
        helper(n->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        ans = 0;
        helper(root, k);
        return ans; 
    }
};
