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

class Codec {
public:

    // Encodes a tree to a single string.
    
    vector<int>str_to_vec(string str){
        vector<int>vec; 
        if(str.size()==0)
            return vec;
        int pos_start = 0;
        int pos_end, delim_len = 1;
        while((pos_end = str.find(",", pos_start)) != string::npos){
        string token = str.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        if(token=="N")
            vec.push_back(INT_MIN);
        else
            vec.push_back(stoi(token));
    }
    string token = str.substr(pos_start);
    if(token=="N")
            vec.push_back(INT_MIN);
        else
            vec.push_back(stoi(token));
    return vec;
    }

    string serialize(TreeNode* root) {

        string ans = "";
        queue<TreeNode*>nodes;
        if(!root)
            return ans;
        nodes.push(root);
        vector<int>vec;

        while(!nodes.empty()){
            int curr_size = nodes.size();
            while(curr_size--){
                TreeNode* n = nodes.front();
                nodes.pop();
                if(!n){
                    vec.push_back(INT_MIN);
                    continue;
                }
                vec.push_back(n->val);
                if(n->left)
                    nodes.push(n->left);
                else
                    nodes.push(NULL);
                
                if(n->right)
                    nodes.push(n->right);
                else
                    nodes.push(NULL);
            }
        }
        for(auto a: vec){
            if(ans.size())
                ans.push_back(',');
            if(a==INT_MIN)
                ans.push_back('N');
            else
                ans = ans + to_string(a);
        }   
        return ans; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout<<data<<" ";
        if(data.size()==0)
            return NULL; 
        queue<TreeNode*>nodes;
        vector<int>vec = str_to_vec(data);
        TreeNode* root = new TreeNode(vec[0]);
        nodes.push(root);
        int ind = 1;
        while(!nodes.empty() && ind < vec.size()){
            int curr_size = nodes.size();
            while(curr_size-- && ind < vec.size()){
                TreeNode* n = nodes.front();
                nodes.pop();
                if(vec[ind]!=INT_MIN)
                {    n->left = new TreeNode(vec[ind]);
                    nodes.push(n->left);
                }
                ind++;
                
                if(vec[ind]!=INT_MIN)
                {    n->right = new TreeNode(vec[ind]);
                    nodes.push(n->right);
                }
                ind++; 
            }
        }
        return root; 

    }
};
