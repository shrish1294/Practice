class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        int cnt = 0;
        vector<bool>vis(n, false);
        map<int, vector<int>>mp;
        queue<int>pq;
        for(auto a: edges){
            mp[a[0]].push_back(a[1]);
            mp[a[1]].push_back(a[0]);
        }
        for(int i = 0; i < n; i++){
            if(vis[i])
                continue;
            pq.push(i);
            cnt++;
            while(!pq.empty()){
                int it = pq.front();
                pq.pop();

                for(auto x: mp[it]){
                    if(vis[x])
                        continue;
                    vis[x] = true;
                    pq.push(x);
                }
            }
        }
        return  cnt;
        
    }
};
