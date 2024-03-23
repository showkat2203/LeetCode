class Solution {
public:
    
    bool isCycle(int u, vector<vector<int>>& g, vector<int>& vis){
        vis[u] = 1;
        for(int i = 0; i < g[u].size(); i++ ){
            int v = g[u][i];
            if( !vis[v] ){
                if( isCycle(v, g, vis) ) return true;
            }
            else if( vis[v] == 1 ){
                return true;
            }
        }
        vis[u] = 2;

        return false;
    }

    bool canFinish(int n, vector<vector<int>>& preq) {
        vector<vector<int>> g(n);
        vector<int> vis(n, 0);
        for( auto x : preq){
            g[x[0]].push_back(x[1]);
        }

        for(int i = 0; i < n; i++ ){
            if( !vis[i] ){
                if( isCycle(i, g, vis) ) return false;
            }
        }

        return true;
    }
};