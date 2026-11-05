class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        map<int, vector<int>>mp;
        for(auto a: edges)
       {     mp[a[0]].push_back(a[1]);
            mp[a[1]].push_back(a[0]);
        }
        queue<int>pq;
        vector<bool>vis(n, false);
        vector<int>parent(n);
        vis[0] = true;
        parent[0] = -1;
        pq.push(0);
        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            for(auto x: mp[it]){
                if(vis[x] && parent[it] != x)
                    return false;
                else if(vis[x])
                    continue;
                pq.push(x);
                vis[x] = true;
                parent[x] = it;
            }
        }
        for(auto a: vis)
            if(a==false)
                return a;
        
        return true;


    }
};
