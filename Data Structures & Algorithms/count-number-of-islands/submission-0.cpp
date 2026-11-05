class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>>vis(m, vector<bool>(n, false));
        queue<pair<int, int>>pq;
        vector<pair<int, int>>dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int cnt =0 ;
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] || grid[i][j]=='0')
                    continue;
                pq.push({i, j});
                cnt++;
                while(!pq.empty()){
                    auto a = pq.front();
                    pq.pop();
                    vis[a.first][a.second] = true;
                    for(auto it: dir)
                    {
                        int x = a.first + it.first;
                        int y = a.second + it.second;
                        if(x <0 || y < 0 || x >=m  || y >= n || vis[x][y] ||
                            grid[x][y]=='0')
                            continue;
                        pq.push({x, y});
                    }
                }
            }
        }
        return cnt;
    }
};
