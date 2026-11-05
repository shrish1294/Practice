class Solution {
public:
    int m , n; 
    vector<pair<int, int>>dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>>vis;
    void fun(set<pair<int ,int>>&st, queue<pair<int, int>>&pq, 
    vector<vector<int>>& grid){
        
        while(!pq.empty()){
            auto a = pq.front();
            pq.pop();
            for(auto d: dir){
                int x = a.first + d.first;
                int y = a.second + d.second;
                if(x < 0 || y < 0 || x >= m || y >=n || vis[x][y]
                || grid[a.first][a.second] > grid[x][y])
                    continue;
                pq.push({x, y});
                vis[x][y] = true;
                st.insert({x, y});
            }
        }
        return ;
        
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vis.clear();
        vis.resize(m, vector<bool>(n, false));
        queue<pair<int, int>>pq;
        set<pair<int, int>>pa, at;
        
        for(int i = 0; i < m; i++){
            if(vis[i][0])
                continue;
            pq.push({i, 0});
            vis[i][0] = true;
            pa.insert({i, 0});
            fun(pa, pq, heights);
        }
        for(int i = 0; i < n; i++){
            if(vis[0][i])
                continue;
            pq.push({0, i});
            pa.insert({0, i});
            vis[0][i] = true;
            fun(pa, pq, heights);
        }
        vis.clear();
        vis.resize(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            if(vis[i][n-1])
                continue;
            pq.push({i, n-1});
            vis[i][n-1] = true;
            at.insert({i, n-1});
            fun(at, pq, heights);

        }
        for(int i = 0; i < n; i++){
            if(vis[m-1][i])
                continue;
            pq.push({m-1, i});
            vis[m-1][i] = true;
            at.insert({m-1, i});
            fun(at, pq, heights);
        }
        vector<pair<int, int>>vec;
        set_intersection(pa.begin(), pa.end(), at.begin(), at.end(),
                        back_inserter(vec));
        
        vector<vector<int>>ans; 
        for(auto a: vec)
            ans.push_back({a.first, a.second});
        
        return ans;
    }
};
