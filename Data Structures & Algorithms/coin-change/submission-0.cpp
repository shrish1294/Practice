class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, INT_MAX);
        sort(coins.begin(), coins.end());
        dp[0] = 0;
        for(int i = 1; i<=amount; i++){
            
            for(auto a: coins){
                if(a > i)
                    break;
                int k = i - a;
                if(k==0)
                    dp[i] = 1;
                else if(dp[k]!=INT_MAX)
                    dp[i] = min(dp[i], dp[k] + 1);
            }
        }
        return (dp[amount]==INT_MAX)? -1: dp[amount];

    }
};
