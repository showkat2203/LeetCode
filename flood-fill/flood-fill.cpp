class Solution {
public:    
    void bfs(int x, int y, int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int color, int prev){
        queue<pair<int, int>> q;
        q.push({x, y});
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        vis[x][y] = 1;
        grid[x][y] = color;
        while( !q.empty() ){
            auto current = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int nx = current.first + dx[i];
                int ny = current.second + dy[i];
                if( nx >= 0 && nx < row && ny >= 0 && ny < col ){
                    if( grid[nx][ny] == prev && !vis[nx][ny] ){
                        grid[nx][ny] = color;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        return ;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        bfs(sr, sc, n, m, image, vis, color, image[sr][sc]);
        
        return image;
    }
};