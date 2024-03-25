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
    int solve(TreeNode* root, int& maxPath){
        if( !root ) return 0;
        int lmax = max(0, solve(root->left, maxPath));
        int rmax = max(0, solve(root->right, maxPath));
        maxPath = max(maxPath, lmax + rmax + root->val);

        return root->val + max(lmax, rmax);
    }
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        solve(root, maxPath);

        return maxPath;
    }
};