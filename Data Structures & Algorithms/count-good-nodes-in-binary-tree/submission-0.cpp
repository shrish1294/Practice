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

    int cnt = 0;
    stack<int>pq;
    void helper(TreeNode* n){
        if(!n)
            return ;
        if(pq.empty() || n->val >= pq.top()){
            pq.push(n->val);
            cnt++;
        }
        helper(n->left);
        helper(n->right);
        if(!pq.empty() && pq.top() == n->val)
            pq.pop();
        return ;
            
    }
    int goodNodes(TreeNode* root) {
        cnt = 0;
        while(!pq.empty())
            pq.pop();
        helper(root);
        return cnt;
    }
};
