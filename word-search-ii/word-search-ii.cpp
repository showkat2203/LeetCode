class TrieNode{
public:
    bool isWord;
    string word;
    TrieNode* children[26];
    TrieNode(){
        isWord = false;
        word = "";
        for(int i = 0; i < 26; i++ ){
            children[i] = nullptr;
        }
    }
    
};


class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    set<string> setAns;
    vector<string> ans;


    void insert(string word){
        TrieNode* cur = root;
        for(char c : word){
            int idx = c - 'a';
            if( !cur->children[idx] )
                cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
            // cout << idx << " " << c << endl;
        }
        cur->isWord = true;
        cur->word = word;
    }


    void backTrack(vector<vector<char>>& board, TrieNode* cur, int i, int j, int m, int n){
        if( i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#' ) return;
        int idx = board[i][j] - 'a';
        if( !cur->children[idx] ) return;
        cur = cur->children[idx];
        if( cur->isWord ) {
            cout << cur->word << endl;
            // setAns.insert(cur->word);
            ans.push_back(cur->word);
            cur->isWord = false;
        }
        char prev = board[i][j];
        board[i][j] = '#';
        for(int k = 0; k < 4; k++ ){
            backTrack(board, cur, i + dx[k], j + dy[k], m, n);
        }
        board[i][j] = prev;

        return;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for(auto x : words){
            insert(x);
        }
        int m = board.size(), n = board[0].size();

        for(int i = 0; i < m; i++ ){
            for(int j = 0; j < n; j++ ){
                backTrack(board, root, i, j, m, n);
            }
        }

        return ans;
    }
private: 
    TrieNode *root;

};