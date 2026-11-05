class Solution {
public:
    vector<int>dp;

    int fun(int i, vector<int>&v, int n){
        if(i >=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int a = v[i] + fun(i+2, v, n);
        int b = fun(i+1, v, n);
        return dp[i] = max(a, b);
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        dp.clear();
        dp.resize(n, -1);
        int ans = fun(0, nums, n-1);
        dp.clear();
        dp.resize(n, -1);
        ans = max(ans, fun(1, nums, n));
        return ans; 
        
    }
};
