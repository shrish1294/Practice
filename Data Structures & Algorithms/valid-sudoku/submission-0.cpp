class Solution {
public:

    bool rowValidator(vector<vector<char>>&board, int row){
        
        int valid = (1<<10) - 1;
        for(int i = 0;i < 9; i++){
            if(board[row][i] == '.')
                continue;
            int val = int(board[row][i] - '0');
            if(!(valid & (1<<val)))
                return false;
            valid^=(1<<val);
        }
        return true;
    }

    bool colValidator(vector<vector<char>>&board, int col){
        int valid = (1<<10) - 1;
        
        for(int i = 0;i < 9; i++){
            if(board[i][col] == '.')
                continue;
            int val = int(board[i][col] - '0');
            if(!(valid & (1<<val)))
                return false;
            valid^=(1<<val);
        }
        return true;
    }

    bool boxValidator(vector<vector<char>>&board, int row, int col){
        int valid = (1<<10) - 1;

        for(int i = row; i < row + 3; i++){
            for(int j = col; j < col + 3; j++)
            {
                if(board[i][j] == '.')
                    continue;
                int val = int(board[i][j] - '0');
               if(!(valid & (1<<val)))
                    return false;
                valid^=(1<<val);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0 ; i < 9; i++){
            if(!rowValidator(board, i))
                return false;
            if(!colValidator(board, i))
                return false;

            for(int j = 0 ; j < 9 &&( i%3 == 0); j+=3){
                if(!boxValidator(board, i, j))
                    return false;
            }
            
        }
        return true; 

    }
};
