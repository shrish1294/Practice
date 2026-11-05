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

  

    int kthSmallest(TreeNode* root, int k) {

        stack<TreeNode*>q;
        vector<int>ans; 
        q.push(root);
        map<TreeNode*, bool>vis;
        
        while(ans.size() < k && !q.empty()){
            
            auto it = q.top();
            if(!it)
                continue;
            if(it->left && vis.count(it->left)){
                ans.push_back(it->val);
                q.pop();
                vis[it] = true;
                if(it->right)
                    q.push(it->right);
            }
            else if(it->left)
                q.push(it->left);
            else{
                 ans.push_back(it->val);
                q.pop();
                vis[it] = true;
                if(it->right)
                    q.push(it->right);   
            }
        }
        return ans.back();

    }
};
