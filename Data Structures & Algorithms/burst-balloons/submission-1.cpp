class Solution {
public:
    int n ;
    vector<vector<int>>dp;
    int helper(int l, int r, vector<int>&v, int i = 1 ,int j = 1){
        if(l > r)
            return 0;
        // if(l == r)
        //     return i*j*v[l];
        int ans = 0;
        if(dp[l][r])
            return dp[l][r];
        for(int k = l; k <=r; k++){
            int a = helper(l, k-1, v, i, v[k]);
            int b = helper(k + 1, r, v, v[k], j);
            
            ans = max(ans, a + b + v[k]*i*j);
        }
        return dp[l][r] = ans; 
    }

    int maxCoins(vector<int>& nums) {
        n = nums.size();
        dp.clear();
        dp.resize(n, vector<int>(n, 0));

        return helper(0, n-1, nums, 1, 1);   
    }
};
