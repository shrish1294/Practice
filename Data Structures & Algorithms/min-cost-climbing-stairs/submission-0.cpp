class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        if(n <=1)
            return cost[n-1];
        
        int p1 = 0; 
        int p2 = 0;
        for(int i = 2; i<= n; i++){
            int val = p1 + cost[i-1];
            int val2 = p2 + cost[i-2];
            p2 = p1;
            p1 = min(val, val2);
        }
        return p1; 
          
    }
};
