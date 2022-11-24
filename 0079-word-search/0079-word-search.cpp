class Solution {
public:
    
    int dx[4] = {-1, 0, 1, 0} ;
    int dy[4] = {0, 1, 0, -1} ;
    bool flag = false;
    int r, c;
    
    void dfs(vector<vector<char>>& board, int x, int y, int len, string goal)
    {
        if(len == goal.size() )
        {
            flag = true;
            return;
        }
        if( x < 0 || y < 0 || x >= r || y >= c || board[x][y] != goal[len] || flag )
            return;
        
//         if( board[x][y] == '#' )
//             return;
        
        char prev_char = board[x][y];
        board[x][y] = '#';
        
        for(int i = 0; i < 4; i++ )
        {
            dfs(board, x + dx[i], y + dy[i], len + 1, goal);
        }
        board[x][y] = prev_char;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        r = board.size();
        c = board[0].size();
        
        
        for(int i = 0; i < r; i++ )
        {
            for(int j = 0; j < c; j++ )
            {
                dfs(board, i, j, 0, word);
                if( flag )
                    return true;
            }
        }
        
        return false;
    }
};