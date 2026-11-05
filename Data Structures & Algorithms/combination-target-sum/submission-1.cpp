class Solution {
public:

    vector<vector<int>>ans ; 

    void fun(vector<int>&v, int t, int i, vector<int>&tmp){
        if( t == 0){
            ans.push_back(tmp);
            return ;
        }
        if(t < 0 || i >=v.size())
            return ;
        tmp.push_back(v[i]);
        fun(v, t-v[i], i, tmp);
        tmp.pop_back();
        fun(v, t, i+1, tmp);

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        ans.clear();
        vector<int>tmp;
        fun(nums, target, 0, tmp);
        return ans; 
    }
};
