class Solution {
public:
   
    int helper(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>&vis){
         vector<vector<int>>dir = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
        if( i>=grid.size() || i < 0 || j >=grid[0].size() || j < 0)
            return 0;
        if(vis[i][j])
            return 0;
        vis[i][j] = true;
        int cnt = 1;
        for(auto a: dir){
            int x = i + a[0];
            int y = j + a[1];
            if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y]==0 
                || vis[x][y])
                    continue;
            cnt += helper(grid, x, y, vis);
        }
        return cnt; 

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>>vis(m, vector<bool>(n, false));

       

        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] || grid[i][j]==0)
                    continue;
                int val = helper(grid, i, j, vis);
                cnt = max(cnt, val);
            }
        }
        return cnt;

    }
};
