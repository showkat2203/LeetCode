class Solution {
public:
    
    bool same_col_or_row(vector<int>& stone1, vector<int>& stone2)
    {
        if( stone1[0] == stone2[0] )
            return true;
        if( stone1[1] == stone2[1] )
            return true;        
        return false;
    }
    
    void dfs(vector<vector<int>>& stones, vector<bool> &visited, int idx, int sz)
    {
        visited[idx] = true;
        for(int i = 0; i < sz; i++ )
        {
            if( !visited[i] && same_col_or_row(stones[i], stones[idx]) )   
            {
                // cout << "H" << endl;
                dfs(stones, visited, i, sz);
            }
        }
        
        return;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int cnt = 0;
        map<int, int> row_mp, col_mp;
        int sz = stones.size();
        vector<bool> visited(sz, false);
        
        for(int i = 0; i < sz; i++ )
        {
            if( !visited[i] )
            {
                cnt++;
                dfs(stones, visited, i, sz);
            }
        }
        
        return sz - cnt;
    }
};