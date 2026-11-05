class Solution {
public:
    
    int uniquePaths(int m, int n) {

    vector<vector<int>>dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int x = (i+1 < m)?dp[i][j]: 0; 
            int y = (j+1 < n)?dp[i][j]: 0;
            if(i+1 < m)
            dp[i+1][j] += x;
            if(j+1 < n)
            dp[i][j+1] += y; 
        }
    }
    return dp[m-1][n-1];  
        
    }
};
