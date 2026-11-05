class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        queue<vector<int>>q;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++)
            for(int j = 0;  j < n; j++)
                if(grid[i][j] == 0)
                    q.push({i, j, 0});
        
        vector<vector<int>>dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!q.empty()){
            auto it = q.front();
            // cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<"\n";
            q.pop();
            for(auto a: dir){
                int x = it[0] + a[0];
                int y = it[1] + a[1];
                if(x < 0 || x >=m || y < 0 || y >= n || grid[x][y] <= 0)
                    continue;
                if(grid[x][y] <= it[2] + 1)
                    continue;
                grid[x][y] = it[2] + 1;
                q.push({x, y, it[2] + 1});
            }
        }


    }
};
