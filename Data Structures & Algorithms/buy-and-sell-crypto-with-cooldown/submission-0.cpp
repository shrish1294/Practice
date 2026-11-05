class Solution {
public:
    int maxProfit(vector<int>& prices) {
        

        int n = prices.size();
        
        vector<int>dp(n+2, 0);
        for(int i = n-2; i>=0; i--){
            dp[i] = dp[i + 1];
            for(int j = i + 1; j <= n-1; j++)
            dp[i] = max(dp[i], dp[j + 2]  + prices[j] - prices[i]);
        }
        for(auto a: dp)
        cout<<a<<" ";
        return dp[0];
    }
};
