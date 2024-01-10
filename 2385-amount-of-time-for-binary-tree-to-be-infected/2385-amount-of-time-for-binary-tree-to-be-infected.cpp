/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> g[100050];
    int sz = 0;
    
    int bfs(int s, int n){
        int cost[n + 10], vis[n + 10];
        memset(cost, 0, sizeof(cost));
        memset(vis, 0, sizeof(vis));

        queue<int> q;
        cost[s] = 0;
        vis[s] = 1;
        q.push(s);
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int i = 0; i < g[x].size(); i++){
                int y = g[x][i];
                if(!vis[y]){
                    vis[y] = 1;
                    cost[y] = cost[x] + 1;
                    q.push(y);
                }
            }
        }
        
        int maxi = 0;
        for(int i = 0; i <= n; i++ ){
            cout << i << "  " << cost[i] << endl;
            maxi = max(maxi, cost[i]);
        } 
        
        
        return maxi;
    }
    
    int traverse(TreeNode* root){
        if( !root ) return sz;
        if( root->left ){
            sz = max(sz, root->val);
            sz = max(sz, root->left->val);
            g[root->val].push_back(root->left->val);
            g[root->left->val].push_back(root->val);
            traverse(root->left);
        }
        if( root->right){
            sz = max(sz, root->val);
            sz = max(sz, root->right->val);
            g[root->val].push_back(root->right->val);
            g[root->right->val].push_back(root->val);
            traverse(root->right);
        }
        return sz;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        
        int n = traverse(root);
        cout << n << endl;
        return bfs(start, n);
        
    }
};