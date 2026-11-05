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

    void helper(TreeNode* n, int h){
        if(!n)
            return ;
        if(!mp.count(h))
            mp[h] = n->val;
        helper(n->right, h + 1);
        helper(n->left, h + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        
        mp.clear();
        helper(root, 0);
        vector<int>v;
        for(auto a = mp.begin(); a!= mp.end(); a++){
            v.push_back(a->second);
        }
        return v; 

    }
};
