class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>>dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        queue<vector<int>>pq;
        for(int i =0; i < m; i++){
            if(board[i][0] == 'O')
            {
                board[i][0] = '-';
                pq.push({i, 0});
            }
            if(board[i][n-1] == 'O'){
                board[i][n-1] = '-';
                pq.push({i, n-1});
            }
        }
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O'){
                board[0][i] = '-';
                pq.push({0, i});
            }
            if(board[m-1][i] == 'O'){
                board[m-1][i] = '-';
                pq.push({m-1, i});
            }
        }

        while(!pq.empty()){

            auto it = pq.front();
            pq.pop();

            for(auto a: dir){
                int x = a[0] + it[0];
                int y = a[1] + it[1];
                if(x < 0 || y < 0 || x >=m || x >=n || board[x][y]!='O')
                    continue;
                board[x][y] = '-';
                pq.push({x, y});
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='-')
                    board[i][j] = 'O';

            }
        }
        
    }
};
