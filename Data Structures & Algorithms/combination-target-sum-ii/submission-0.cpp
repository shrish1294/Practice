class Solution {
public:

    set<vector<int>> ans; 

    void helper(vector<int>&v, int t, int i, vector<int>&tmp){
        
        if(t == 0){
            auto it  = tmp;
            sort(it.begin(), it.end());
            ans.insert(it);
            return ;
        }
        if(i >=v.size() || t < 0)
            return ;
        tmp.push_back(v[i]);
        helper(v, t - v[i], i + 1, tmp);
        tmp.pop_back();
        helper(v, t , i + 1, tmp);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        vector<int>tmp; 
        helper(candidates, target, 0, tmp);
        vector<vector<int>>v;
        for(auto a: ans)
            v.push_back(a);
        return v;  

    }
};
