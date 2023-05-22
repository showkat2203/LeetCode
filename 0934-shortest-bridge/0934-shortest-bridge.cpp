class Solution {
public:
    int dx[4] = {-1, 1, 0, 0}; 
    int dy[4] = {0, 0, -1, 1};
    
    vector<pair<int, int>> first_island;
    vector<pair<int, int>> second_island;
    
    void mark(int r, int c, int island_no, vector<vector<int>>& grid){
        
        if( r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != 1 )  return;
        
        grid[r][c] = island_no;
        
        if( island_no == 2 ) first_island.push_back({r, c});
        else second_island.push_back({r, c});
        
        for(int i = 0; i < 4; i++ ) {
            mark(r + dx[i], c + dy[i], island_no, grid);
        }
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        int cnt = 2;
        
        for(int i = 0; i < grid.size(); i++ ){
            for(int j = 0; j < grid[0].size(); j++ ){
                if( grid[i][j] == 1 ){
                    mark(i, j, cnt, grid);
                    cnt++;
                }
            }
        }
        
        int ans = 10000;
        
        int fst_size = first_island.size(); 
        int scnd_size = second_island.size(); 
        
        for(int i = 0; i < fst_size; i++ ) {
            for(int j = 0; j < scnd_size; j++ ) {
                ans = min( abs( first_island[i].first - second_island[j].first ) + abs( first_island[i].second - second_island[j].second ) - 1, ans );
            }
        }
        
        return ans;
        
    }
};