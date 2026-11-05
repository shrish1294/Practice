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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(!root)
            return v;
        queue<vector<TreeNode*>>st;
        st.push({root});
        while(!st.empty()){
            vector<TreeNode*>b = st.front();
            st.pop();
            vector<int>ans; 
            vector<TreeNode*>p; 
            for(int i = 0 ; i < b.size(); i++){
                ans.push_back(b[i]->val);
                if(b[i]->left)
                    p.push_back(b[i]->left);
                if(b[i]->right)
                    p.push_back(b[i]->right);
            }
            if(p.size())
            st.push(p);
            v.push_back(ans);
        }
        return v;
    }
};
