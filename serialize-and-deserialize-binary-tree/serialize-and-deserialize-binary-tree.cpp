/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {
        if( !root ) return "null";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* makeTree(int &pos, vector<string> &nodes){
        if( pos >= nodes.size() || nodes[pos] == "null" ){
            pos++;
            return nullptr;
        }
        int val = atoi(nodes[pos].c_str());
        TreeNode* newNode = new TreeNode(val);
        pos++;
        newNode->left = makeTree(pos, nodes);
        newNode->right = makeTree(pos, nodes);
        return newNode;
    }

    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        vector<string> nodes;
        istringstream ss(data);
        string token;
        while(getline(ss, token, ',') ){
            nodes.push_back(token);
        }
        int pos = 0;
        return makeTree(pos, nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));