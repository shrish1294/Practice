class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        queue<vector<int>>pq;
        for(int i =0 ; i < m; i++){
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 2){
                    pq.push({i, j, 0});
                    grid[i][j] = -1;
                }
        }

        vector<vector<int>>dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int ans = 0; 
        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();

            for(auto a: dir){
                int x = it[0] + a[0];
                int y = it[1] + a[1];
                
                if(x < 0 || x >=m || y < 0 || y >= n || grid[x][y] <= 0)
                    continue;
                grid[x][y] = -1;
                pq.push({x, y, it[2] + 1});
                ans  =max(ans, it[2] + 1);
            }
        }
        for(auto a: grid)
            for(auto b: a)
                if(b == 1)
                    return -1;
        return ans; 

    }
};
