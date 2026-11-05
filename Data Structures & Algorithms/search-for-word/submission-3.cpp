class Solution {
public:

    vector<vector<bool>>vis; 

    bool helper(vector<vector<char>>& board, string &s, int i,
    int x, int y){
        if(i >= s.length())
            return true;
        if(x >=board.size() || y >= board[0].size())
            return false;
        vector<vector<int>>dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        bool ans = false;
        for(auto a: dir){
            int m = a[0] + x;
            int n = a[1] + y;
            if(m >=board.size() || n >= board[0].size() || m < 0 ||  n < 0 || vis[m][n] || 
                board[m][n] != s[i])
                continue;
            vis[m][n] = true;
            ans |= helper(board, s, i + 1, m, n);
            vis[m][n] = false;
            if(ans)
                return ans;
        }
        return ans; 
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        vis.clear();
        vis.resize(board.size(), vector<bool>(board[0].size(), false));
        bool ans = false;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(word[0] != board[i][j])
                    continue;
                vis[i][j] = true; 
                ans |= helper(board, word, 1, i, j);
                if(ans)
                    return ans;
                vis[i][j] = false; 
            }
        }
        return ans; 
    }
};
