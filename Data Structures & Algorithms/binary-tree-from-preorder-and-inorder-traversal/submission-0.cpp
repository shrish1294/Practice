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
    TreeNode* fun(vector<int>&a, vector<int>&b, int la , int ra, int lb, int rb){
        if(la > ra)
            return NULL; 
        if(la==ra)
            return new TreeNode(a[la]);
        
        int root_idx ;
        TreeNode* root = new TreeNode(b[lb]);
        for(int i = la; i<=ra; i++){
            if(b[lb] == a[i])
           {     root_idx = i; 
                 break;
            }
        }
        int len = root_idx - la; 
        root->left = fun(a, b, la, root_idx-1, lb+1, lb + len);
        root->right = fun(a, b, root_idx+ 1, ra,  lb + len+ 1, rb);
        return root; 
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n1 = inorder.size();
        int n2 = preorder.size();
        
        return fun(inorder, preorder, 0, n1-1, 0, n2-1);
     
    }
};
