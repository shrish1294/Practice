class Solution {
public:
    map<int, bool>row;
    map<int, bool>col; 
    map<int, bool>left_d;
    map<int, bool>right_d;
    vector<vector<string>>ans; 

    void solve(int j, vector<string>&board, int n, int q){
        if(q == 0){
            ans.push_back(board);
            return ;
        }
        if( j >= n)
            return ;
        
        for(int i = 0; i < n; i++){
        if(row[i] || col[i] || left_d[i + j] || right_d[n -1 - i + j])
            continue;
        row[i] = true;
        left_d[i + j] = true;
        right_d[n -1 - i + j] = true;
        board[i][j] = 'Q';
        solve(j + 1, board, n, q-1);
        row[i] = false;
        left_d[i + j] = false;
        right_d[n -1 - i + j] = false;
        board[i][j] = '.';
        }
        // solve(i + 1, 0, s, board, n, q-1);
       
    } 


    vector<vector<string>> solveNQueens(int n) {
        row.clear();
        col.clear();
        left_d.clear();
        right_d.clear();
        ans.clear();

        vector<string>board;
        for(int i = 0; i < n; i++){
            string s(n, '.');
            board.push_back(s);
        }
        solve( 0,board, n, n);

        return ans;
        
    }
};
