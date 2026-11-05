class Solution {
public:
    vector<vector<bool>>vis;
    int m, n;
    bool check(vector<vector<char>>&v, string &word, int i, 
    int x, int y){
        if(i == word.length())
            return true;
        vector<pair<int, int>> dir = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
        if(v[x][y]!=word[i])
            return false;
        else if(v[x][y] == word[i] && i+1 == word.length())
            return true;
        for(auto a: dir){
            int X = x + a.first;
            int Y = y + a.second;
            
            if(X >= m || X < 0 || Y >=n || Y < 0 || vis[X][Y])
                continue;
            vis[X][Y] = true;
            if(check(v, word, i+1, X, Y))
                return true;
            vis[X][Y] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        vis.clear();
        m = board.size();
        n = board[0].size();
        vis.resize(m, vector<bool>(n, false)); 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                vis[i][j] = true;
                if(check(board, word, 0,i, j))
                    return true;
                vis[i][j] = false;
            }
        }

        return false;


        
    }
};
