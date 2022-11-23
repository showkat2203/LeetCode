class Solution {
public:
    
    int memo[10];
    
    bool row_col_check(vector<vector<char>>& board)
    {
        for(int i = 0; i < 9; i++ )
        {
            memset(memo, 0, sizeof(memo));
            for(int j = 0; j < 9; j++ )
            { 
                if( board[i][j] != '.')     
                {
                    memo[board[i][j] - '0']++;
                    if(memo[board[i][j] - '0'] > 1)
                    {
                        return false;
                    }
                }
            }
        }
        
        for(int i = 0; i < 9; i++ )
        {
            memset(memo, 0, sizeof(memo));
            for(int j = 0; j < 9; j++ )
            { 
                if( board[j][i] != '.')     
                {
                    memo[board[j][i] - '0']++;
                    if(memo[board[j][i] - '0'] > 1)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
        
    }
    
    bool box_check(vector<vector<char>>& board, int r, int c)
    {
        memset(memo, 0, sizeof(memo));
        for(int i = r; i < r + 3; i++ )
        {
            for(int j = c; j < c + 3; j++ )
            {
                if( board[i][j] != '.')     
                {
                    memo[board[i][j] - '0']++;
                    if(memo[board[i][j] - '0'] > 1)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    bool check(vector<vector<char>>& board)
    {
        
        if( !row_col_check(board) )
            return false;
        
        for(int i = 0; i < 9; i += 3 )
        {
            for(int j = 0; j < 9; j += 3)
            {
                if( !box_check(board, i, j) )
                    return false;
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        return check(board);
    }
};