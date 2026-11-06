class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<vector<int>>>gr(n); 
        for(auto a: flights){
            gr[a[0]].push_back({a[1], a[2]});
        }
        if(src == dst)
            return 0; 
        


        vector<vector<int>>dp(n + 1, vector<int>(k + 2, INT_MAX));

        set<vector<int>>pq; 
        
        pq.insert({0, src});
        for(int i = 0; i <=k; i++){
            dp[src][i] = 0; 
        }

        while(!pq.empty()){
            int sz = pq.size();
            while(sz--){
                auto it = *pq.begin();
                pq.erase(pq.begin());
                if(it[0] > k)
                    continue; 
                // if(it[1] == dst)
                //     return dp[dst][it[0]];
                // cout << pq.size()<<"\n";

                for(auto a: gr[it[1]]){
                    int cost = a[1] + dp[it[1]][it[0]];
                    // cout << cost<<" " << dp[a[0]][it[0] + 1]; 
                    if(cost > dp[a[0]][it[0] + 1])
                        continue; 
                
                    dp[a[0]][it[0] + 1] = cost;
                    pq.insert({it[0] + 1, a[0]});
                }
            }
        }

        int mini = INT_MAX;
        for(auto a :dp[dst])
            mini = min(a, mini);
        
        if(mini == INT_MAX)
            return -1;
        return mini;

        
        
    }
};
