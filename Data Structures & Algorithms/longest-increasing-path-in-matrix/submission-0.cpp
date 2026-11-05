class Solution {
public:

    vector<vector<int>>dp;
    int m, n;
    vector<vector<int>>dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int helper(int i, int j, vector<vector<int>>&v){
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = 0;
        for(auto a: dir){
            int x = i + a[0];
            int y = j + a[1];
            if(x < 0 || y < 0 || x>=m || y>=n || v[i][j] >= v[x][y])
                continue;
            ans = max(ans, helper(x, y, v));
        }
        return dp[i][j]  = 1 + ans; 
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();
        dp.clear();
        dp.resize(m, vector<int>(n, -1));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j] == -1)
                    helper(i, j, matrix);
                ans = max(ans, dp[i][j]);
                
            }
        }
        return ans;    
    }
};
