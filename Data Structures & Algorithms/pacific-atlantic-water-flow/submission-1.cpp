class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
            int m = heights.size();
            int n = heights[0].size();
            vector<vector<int>>dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            queue<vector<int>>pq;
            vector<vector<bool>>vis1(m, vector<bool>(n, 0));
            vector<vector<bool>>vis2(m, vector<bool>(n, 0));

            for(int i =0; i< m; i++){
                if(!vis1[i][0])
                pq.push({i, 0});
                
                vis1[i][0] = 1;
            }
            for(int i = 0; i < n; i++){
                if(!vis1[0][i])
                pq.push({0, i});
                vis1[0][i] = 1;
            }
            while(!pq.empty()){
                auto it = pq.front();
                pq.pop();
                for(auto a: dir){
                    int x = a[0] + it[0];
                    int y = a[1] + it[1];
                    if(x < 0 || y < 0 || x >= m || y >=n || vis1[x][y])
                        continue;
                    if(heights[it[0]][it[1]] > heights[x][y])
                        continue;
                    vis1[x][y] = 1;
                    pq.push({x, y});
                }
            }
             for(int i =0; i < m; i++){
                if(!vis2[i][n-1])
                pq.push({i, n-1});
                vis2[i][n-1] = 1;
            }
            for(int i = 0; i < n; i++){
                if(!vis2[m-1][i])
                pq.push({m-1, i});
                vis2[m-1][i] = 1;
            }
             while(!pq.empty()){
                auto it = pq.front();
                pq.pop();
                for(auto a: dir){
                    int x = a[0] + it[0];
                    int y = a[1] + it[1];
                    if(x < 0 || y < 0 || x >= m || y >=n || vis2[x][y])
                        continue;
                    if(heights[it[0]][it[1]] > heights[x][y])
                        continue;
                    vis2[x][y]  = 1;
                    pq.push({x, y});
                }
            }

            vector<vector<int>>ans;
            for(int i = 0; i < m; i++)
                for(int j = 0; j < n; j++){
                    if(vis1[i][j] && vis2[i][j])
                        ans.push_back({i,j});
                    // cout<<vis[i][j]<<" ";
                }
            return ans; 


    }
};
