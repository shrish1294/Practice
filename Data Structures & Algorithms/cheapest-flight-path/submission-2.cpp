class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<vector<int>>>gr(n);
        for(auto a: flights){
            gr[a[0]].push_back({a[1], a[2]});
        }
        k++;
        set<vector<int>>st;
        st.insert({0, 0, src});
        vector<bool>vis(n, 0);
        vector<int>dis(n, INT_MAX);

        while(st.size()){
            auto it = *st.begin();
            // cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<"\n";
            st.erase(st.begin());
            
            dis[it[2]] = min(it[0],  dis[it[2]]);
            
             if(it[1] == k)
                continue;
            vis[it[2]] = true;
            for(auto a: gr[it[2]]){
                if(vis[a[0]])
                    continue;
                int d = it[0] + a[1];
                // if(d > dis[a[0]])
                //     continue;
                // dis[a[0]] = min(d, dis[a[0]]);
                st.insert({d, it[1] + 1, a[0]});
            }
        }
        if(dis[dst] == INT_MAX)
            return -1;

        return dis[dst];
       
    }
};
