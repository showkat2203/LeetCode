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
    int ans = 0;
    int fidDia(TreeNode* root){
        if( !root ) return 0;
        int lh = fidDia(root->left);
        int rh = fidDia(root->right);
        ans = max(ans, rh + lh);
        return 1 + max(rh, lh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        fidDia(root);
        return ans;
    }
};