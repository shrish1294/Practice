class Solution {
public:
    int maxProfit(vector<int>& prices) {
        

        int n = prices.size();

        vector<int>dp(n+2, 0);

        int maxi = prices[n-1];
        for(int i = n-2; i>=0; i--){
            dp[i] = dp[i + 1];
            // for(int j = i + 1; j <= n-1; j++)
            dp[i] = max(dp[i], maxi - prices[i]);
            maxi = max(maxi, dp[i + 2]  + prices[i]);
        }
        for(auto a: dp)
        cout<<a<<" ";
        return dp[0];
    }
};
