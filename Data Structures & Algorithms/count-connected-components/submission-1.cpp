class Solution {
public:
    vector<vector<int>>gr;
    void dfs(int i, vector<bool>&vis){
        if(vis[i])
            return ;
        vis[i] = true; 
        for(auto a: gr[i]){
            if(vis[a])
                continue;
            dfs(a, vis);
        }
        return ;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        gr.clear();

        gr.resize(n);
        for(auto a: edges){
            gr[a[0]].push_back(a[1]);
            gr[a[1]].push_back(a[0]);
        }
        vector<bool>vis(n, 0);
        int cnt  = 0;
        for(int i = 0; i < n; i++){
            if(vis[i])
                continue;
            dfs(i, vis);
            cnt++;
        }
        return cnt;
    }
};
