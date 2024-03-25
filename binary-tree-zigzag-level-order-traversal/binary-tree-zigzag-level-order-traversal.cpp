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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if( !root ){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        int cur_level = 0;
        while( !q.empty() ){
            int sz = q.size();
            vector<int> levels;
            for(int i = 0; i < sz; i++ ){
                TreeNode* front = q.front(); q.pop();
                levels.push_back(front->val);
                if( front->left ){
                    q.push(front->left);
                }
                if( front->right ){
                    q.push(front->right);
                }
            }
            if( cur_level % 2 == 1 ){
                reverse(levels.begin(), levels.end());
            }
            ans.push_back(levels);
            cur_level += 1;
        }

        return ans;
    }
};