class Solution {
public:

    vector<vector<int>>gr;

    bool dfs(int i, vector<bool>&vis, int p){

        if(vis[i])
            return true;
        vis[i] = true; 
        for(auto a: gr[i]){
            if(a == p)
                continue;
            if(vis[a])
                return false;
            auto x = dfs(a, vis,  i);
            if(!x)
                return x;
        }
        return true; 
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        gr.clear();
        gr.resize(n+1);
        for(auto a: edges){
            gr[a[0]].push_back(a[1]);
            gr[a[1]].push_back(a[0]);
        }
        vector<bool>vis(n, 0);
        if(!dfs(0, vis, -1))
            return false;
        for(auto a: vis)
            if(!a)
                return false;
        return true;


    }
};
