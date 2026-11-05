class Solution {
public:

    int cnt = 0;
    vector<map<int, int>>dp;
    int helper(int i, vector<int>&v, int target){
        if(i >=v.size())
            return target == 0;
        
        if(dp[i].count(target))
            return dp[i][target];
        int a = helper(i + 1, v, target- v[i]);
        int b = helper(i + 1, v, target + v[i]);
        return dp[i][target] = a + b;    
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        dp.clear();
        cnt = 0;
        dp.resize(nums.size());
        int val = helper(0, nums, target);
            cout<<cnt<<" ";
        return val;
    }
};
