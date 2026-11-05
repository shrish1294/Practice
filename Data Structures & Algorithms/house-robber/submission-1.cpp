class Solution {
public:
    vector<int>dp;
    int fun(int i, vector<int>&v){
        if(i >=v.size())
            return 0;
        if(dp[i]!=INT_MIN)
            return dp[i];
        int a = v[i] + fun(i + 2, v);
        int b = fun(i+1, v);
        return dp[i] = max(a ,b);
    }
    int rob(vector<int>& nums) {
        
        dp.clear();
        int n = nums.size();
        dp.resize(n, INT_MIN);
        return fun(0, nums);
    }
};
