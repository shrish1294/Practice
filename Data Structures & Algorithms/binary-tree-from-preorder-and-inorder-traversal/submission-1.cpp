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


    map<int, int>mp;

    TreeNode* helper(vector<int>&preorder, int i, int l , int r){
        if(l > r)
            return NULL;
        int val = preorder[i];
        TreeNode * n = new TreeNode(val);
        int idx = mp[val];

        n->left = helper(preorder, i + 1, l, idx - 1);
        n->right = helper(preorder, i + idx - l + 1, idx + 1, r);
        return n; 
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        mp.clear();
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i ;
        
        return helper(preorder, 0, 0, inorder.size() - 1);




    }
};
