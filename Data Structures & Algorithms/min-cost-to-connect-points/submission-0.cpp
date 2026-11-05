class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<bool>vis(n, 0);
        
        vector<int>dist(n, INT_MAX);
        int node = 0;
        int ans  = 0;
        for(int i = 0; i <n && node != -1 ; i++){
            int next_node = -1;
            vis[node] = true; 
            for(int j = 0; j < n; j++){
                if(vis[j])
                    continue;
                int d = abs(points[j][0] - points[node][0]) 
                        + abs(points[j][1] - points[node][1]);
             
                dist[j] = min(d, dist[j]); 
                
                if(next_node == -1 || dist[j] < dist[next_node])
                    next_node = j;

            }
            cout<<next_node<<" ";
            if(next_node != -1)
            ans += dist[next_node];
            node = next_node; 
        }
        return ans; 
    }
};
