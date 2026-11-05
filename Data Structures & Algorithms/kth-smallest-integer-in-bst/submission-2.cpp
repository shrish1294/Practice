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

    pair<int , int> fun(TreeNode* root, int k){
        if(!root)
            return {0 , 0};

        pair<int, int> ans = {k, root->val};
        
        if(root->left){
            auto val = fun(root->left, k);
            if(val.first!=1){
                ans = {val.first-1, root->val};
            }
            else
             ans =  val;
        }

        if(ans.first == 1)
            return ans;
        
        if(root->right){
            auto val = fun(root->right, ans.first - 1);
            return val; 
        }
        
        return ans; 

    }

    int kthSmallest(TreeNode* root, int k) {
        
        auto val = fun(root, k);
        return val.second; 

    }
};
