class Solution {
public:
    void bfs(int x, int y, int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
        queue<pair<int, int>> q;
        q.push({x, y});
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        vis[x][y] = 1;
        while( !q.empty() ){
            auto current = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int nx = current.first + dx[i];
                int ny = current.second + dy[i];
                if( nx >= 0 && nx < row && ny >= 0 && ny < col ){
                    if( grid[nx][ny] == '1' && !vis[nx][ny] ){
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < grid.size(); i++ ){
            for(int j = 0; j < grid[0].size(); j++){
                if( !vis[i][j] && grid[i][j] == '1' ){
                    bfs(i, j, n, m, grid, vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};