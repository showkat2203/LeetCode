class Solution {
public:
    
    int vis[2010];
    vector<int> graph[2010];
    int indegree[2010];
    bool mark[2010];
    bool cycle;
    
    void topo_sort(int parent)
    {
        if(cycle || mark[parent]) return;
        mark[parent] = 1;
        vis[parent] = 1;
        int sz = graph[parent].size();
        
        for(int i = 0; i < sz; i++ )
        {
            int child = graph[parent][i];
            if( vis[child] == 0 )
            {
                topo_sort(child);
            }
            else
            {
                cycle = true;
            }
        }
        vis[parent] = 0;
        return;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        for(int i = 0; i < 2010; i++ )
        {
            graph[i].clear();
            vis[i] = 0;
            indegree[i] = 0;
            mark[i] = 0;
        }
        
        int sz = prerequisites.size();
        
        if( sz == 0 )
            return true;
        
        bool ans = true;
        
        for(int i = 0; i < sz; i++ )
        {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            graph[y].push_back(x);
            indegree[x]++;
        }
        
        cycle = false;
        
        for(int i = 0; i < numCourses; i++ )
        {
            if( indegree[i] == 0 && vis[i] == 0 )
            {
                cout << "DFS start   " << i << endl;
                topo_sort(i);
                // break;
            }
        }
        
        cout << "Cycle Exist " << cycle << " " << endl;
        

        for(int i = 0; i < numCourses; i++ )
        {
            if( mark[i] == 0 )
                return false;
        }
        
        return !cycle;
    }
};