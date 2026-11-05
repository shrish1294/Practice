class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        queue<vector<int>>pq;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j]==0)
                    pq.push({i, j});
        
        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            int i = it[0];
            int j = it[1];
            for(int k = 0; k < n; k++)
                matrix[i][k] = 0;
            for(int k = 0; k < m; k++)
                matrix[k][j] = 0;
        }
    }
};
