class Solution {
public:
    set<vector<int>>ans; 
    void fun(vector<int>&v, int i, int curr, vector<int>&vec,
    int target){
        if(curr == target){
            cout<<"fefe";
            ans.insert(vec);
            return ;
        }
        if(i >=v.size() || curr > target)
            return ;
        fun(v, i+1, curr, vec, target);
        vec.push_back(v[i]);
        fun(v, i, curr + v[i], vec, target);
        vec.pop_back();
        return ;

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       ans.clear(); 
        vector<int>vec;
        fun(nums, 0, 0, vec, target);
        vector<vector<int>>v;
        for(auto a: ans){
            v.push_back(a);
        }
        return v;
    }
};
