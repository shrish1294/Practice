class Solution {
public:

    vector<vector<int>>ans; 

    void helper(vector<int>&v, int i, vector<int>&tmp, vector<bool>&vis){
        if(i == v.size()){
            ans.push_back(tmp);
            return ;
        }
        for(int j = 0; j < v.size(); j++){
            if(vis[j])
                continue;
            tmp.push_back(v[j]);
            vis[j] = true;
            helper(v, i + 1, tmp, vis);
            vis[j] = false;
            tmp.pop_back();
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        ans.clear();
        int n = nums.size();
        vector<bool>vis(n, false);
        vector<int>tmp;
        helper(nums, 0, tmp, vis);
        return ans; 
    }
};
