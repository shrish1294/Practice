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

    bool is_valid = true;

    pair<int, int> helper(TreeNode* n, bool is_left = false){
        if(!n || !is_valid)  
        return {INT_MIN, INT_MAX}; 
       
        if(n->left && n->left->val >= n->val)
        {
            is_valid = false;
            return {INT_MIN, INT_MAX};
        }
        if(n->right && n->right->val <= n->val)
        {
            is_valid = false;
            return {INT_MIN, INT_MAX};
        }
        auto a1 = helper(n->left, true);
        auto a2 = helper(n->right);
        if(!is_valid)
            return {INT_MIN, INT_MAX};
        
       
       if(a1.second != INT_MAX && a1.second >= n->val){
            is_valid = false;
            return {INT_MIN, INT_MAX};
       }
       if(a2.first != INT_MIN && a2.first <= n->val){
            is_valid = false;
            return {INT_MIN, INT_MAX};
        }

        int mini = n->val, maxi = n->val; 
        if(a1.first != INT_MIN && a1.first != INT_MAX)
            mini = min(mini, a1.first);
        if(a2.first != INT_MIN && a2.first != INT_MAX)
            mini = min(mini, a2.first);
        
        if(a1.second != INT_MIN && a1.second != INT_MAX)
            maxi = max(maxi, a1.second);
        
        if(a2.second != INT_MIN && a2.second != INT_MAX)
            maxi = max(maxi, a2.second);
        // cout<<n->val<<" "<<mi
        return {mini, maxi};



    }

    bool isValidBST(TreeNode* root) {
        is_valid = true;

        helper(root);
        return is_valid;
    }
};
