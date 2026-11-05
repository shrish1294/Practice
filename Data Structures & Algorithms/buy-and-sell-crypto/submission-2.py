class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        mini = prices[-1]
        n = len(prices)
        ans = 0
        for i in range(n - 1, -1, -1):
            ans = max(ans, mini - prices[i] )
            mini = max(mini, prices[i])
        
        return ans