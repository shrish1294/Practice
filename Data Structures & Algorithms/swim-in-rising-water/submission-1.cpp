class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        vector<vector<int>>dis(m, vector<int>(n, INT_MAX));
        vector<vector<int>>dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        set<vector<int>>st;
        st.insert({grid[0][0], 0, 0});
        dis[0][0] = 0;
       
        while(st.size()){
            auto it = *st.begin();
            st.erase(st.begin());
            int i = it[1], j = it[2];
            int d = it[0];
            vis[i][j] = true;
            dis[i][j] = d;
            if(i == m-1 && j == n-1)
                break;
            for(auto a: dir){
                int x = a[0] + i;
                int y = a[1] + j;
                if(x <0 || x >= m || y < 0 || y>=n || vis[x][y])
                    continue;
                    st.insert({max(dis[i][j], grid[x][y]), x, y});
            }
        }
        for(auto a: dis){
            for(auto b: a)
                cout<<b<<" ";
            cout<<"\n";
        }

        return dis[m-1][n-1]; 


    }
};
