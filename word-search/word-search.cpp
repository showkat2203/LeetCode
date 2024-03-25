class Solution {
public:
    int flag = 0;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int vis[10][10];
    void search(int pos, string tmp, vector<vector<char>>& board, int r, int c, string word){
        vis[r][c] = 1;
       
        if( tmp == word ){
            flag = 1;
            return;
        }
        for(int i = 0; i < 4; i++ ){
            int nx = dx[i] + r;
            int ny = dy[i] + c;
            if( nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() ){
                if( pos < word.size() && word[pos] == board[nx][ny] && !vis[nx][ny] ){
                    tmp += board[nx][ny];
                    search(pos + 1, tmp, board, nx, ny, word);
                    tmp.pop_back();
                }
            }
        }
        vis[r][c] = 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < board.size(); i++ ){
            for(int j = 0; j < board[0].size(); j++ ){
                if( board[i][j] == word[0] ){
                    string tmp = "";
                    tmp += board[i][j];
                    search(1, tmp, board, i, j, word );
                    if( flag  ){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};