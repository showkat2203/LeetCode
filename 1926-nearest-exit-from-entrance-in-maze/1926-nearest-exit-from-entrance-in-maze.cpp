class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        queue<pair<int, int>> q;
        int cnt = 0;
        
        int s_x = entrance[0];
        int s_y = entrance[1];
        int row_sz = maze.size();
        int col_sz = maze[0].size();
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        vector<vector<bool>> visited(row_sz, vector<bool>(col_sz, false));
        vector<vector<int>> cost(row_sz, vector<int>(col_sz, -1));
        
        
        q.push(make_pair(s_x, s_y));
        visited[s_x][s_y] = true;
        cost[s_x][s_y] = 0;
        
        while( !q.empty() )
        {
            auto tmp = q.front();
            q.pop();
            int x = tmp.first;
            int y = tmp.second;
            
            for(int i = 0; i < 4; i++ )
            {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if( tx >= 0 && tx < row_sz && ty >= 0 && ty < col_sz )
                {
                    if( maze[tx][ty] == '.' && visited[tx][ty] == false )
                    {
                        visited[tx][ty] = true;
                        cost[tx][ty] = cost[x][y] + 1;
                        if( tx == 0 || ty == 0 || tx == row_sz - 1 || ty == col_sz - 1 )
                        {
                            return cost[tx][ty];
                        }
                        
                        q.push(make_pair(tx, ty));
                        
                    }
                }
            }
            
            
        }
        
        
        return -1;
    }
};