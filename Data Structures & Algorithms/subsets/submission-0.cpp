class Solution {
public:

    vector<vector<int>>ans ;
    void fun(vector<int>&v, int i, vector<int>&tmp){
        if(i >=v.size()){
            ans.push_back(tmp);
            return ;
        }
        tmp.push_back(v[i]);
        fun(v, i + 1, tmp);
        tmp.pop_back();
        fun(v, i + 1, tmp);
        return ;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        ans.clear();
        vector<int>tmp;
        fun(nums, 0, tmp);
        return ans;
    }
};
