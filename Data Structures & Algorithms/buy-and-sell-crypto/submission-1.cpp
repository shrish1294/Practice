class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int ans = 0;
        int left_min = prices[0];
        int len = prices.size();
        for(int i = 1; i < len; i++){
            ans = max(ans, prices[i] - left_min);
            left_min = min(left_min, prices[i]);
        } 
        return ans; 

    }
};
