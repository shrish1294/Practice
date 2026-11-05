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
    bool ans; 
    pair<int, int> fun(TreeNode* node){
        if(!node)
            return {0, 0};
        int mini = node->val;
        int maxi = node->val;  
        if(node->left){
            auto val = fun(node->left);
            if(val.first >= node->val || val.second >= node->val){
                ans = false;
            }
            maxi = max(maxi, max(val.first, val.second));
            mini = min(mini, min(val.first, val.second));

        }
        if(node->right){
            auto val = fun(node->right);
            if(val.first <= node->val || val.second<=node->val){
                ans = false;
            }
            
            maxi = max(maxi, max(val.first, val.second));
            mini = min(mini, min(val.first, val.second));
        }
        return {mini, maxi}; 
    }


    bool isValidBST(TreeNode* root) {
        ans = true;
        if(!root || (!root->left && !root->right))
            return true;

        if(root->left){
        auto v1 = fun(root->left);
        if(!ans)
            return false;
        
        if(v1.first >= root->val || v1.second >=root->val)
            return false;
        }
        if(!root->right)
            return true;

        auto v2 = fun(root->right);
        if(!ans)
            return false;
       
        if(v2.first <=root->val || v2.second <= root->val)
            return false;
        return true;

    }
};
