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

    TreeNode* helper(TreeNode* root,  TreeNode* p, TreeNode* q, bool &_p, bool &_q){
        if(!root)
            return root;

        bool found_p = false, found_q = false;
        TreeNode* v1 = helper(root->left, p, q, _p, _q);
        if(v1!=NULL)
            return v1;
        if(_p){
            found_p = true; 
            _p = false;
        }
        if(_q){
            found_q = true;
            _q = false;
        }


        TreeNode* v2 = helper(root->right, p, q, _p, _q);
        if(_p){
            found_p = true; 
            _p = false;
        }
        if(_q){
            found_q = true;
            _q = false;
        }
        if(v2!=NULL )
            return v2;
        if(p->val == root->val)
            found_p = true;
        if(q->val == root->val)
            found_q = true;
        
        if(found_p&found_q)
            return root;
        _p = found_p; 
        _q = found_q;

        return NULL; 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
       if(root->val == p->val  || root->val == q->val)
            return root; 
        
        bool p_val = false;
        bool q_val = false;
        TreeNode* val =  helper(root, p, q, p_val, q_val);


        if(val == NULL){
            cout<<"null val";
        return root;
        }
        return val;
        
        
    }
};
