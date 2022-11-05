class Solution {
public:
    
    
    // idea copied
    
    struct TrieNode
    {
        bool is_end;
        string word;
        TrieNode* child[26];
        
        TrieNode()
        {
            is_end = false;
            word = "";
            for(int i = 0; i < 26; i++ )
                child[i] = NULL;
        }
    };
    
    TrieNode *root = new TrieNode();
    int row, col;
    
    void insert_in_trie(string word)
    {
        int sz = word.size();
        TrieNode *cur = root;
        for(int i = 0; i < sz; i++ )
        {
            int idx = word[i] - 'a';
            if( cur->child[idx] == NULL )
                cur->child[idx] = new TrieNode();
            
            cur = cur->child[idx];
        }
        
        cur->is_end = true;
        cur->word = word;
    }
    
    int dx[4] = {-1, 0, 1, 0} ;
    int dy[4] = {0, 1, 0, -1} ;
    vector<string> ans;
    
    
    
    void dfs(vector<vector<char>>& board, int x, int y, TrieNode *cur)
    {
        if( x < 0 || y < 0 || x >= row || y >= col )
            return;
        if( board[x][y] == '#' )
            return;
        
        int idx = board[x][y] - 'a';
        
        if( cur->child[idx] == NULL )
            return;
        
        cur = cur->child[idx] ;
        
        if( cur->is_end == true )
        {
            ans.push_back(cur->word);
           cur->is_end = false;
        }
        char prev_char = board[x][y];
        
        board[x][y] = '#';
        
        for(int i = 0; i < 4; i++ )
        {
            dfs(board, x + dx[i], y + dy[i], cur);
        }
        board[x][y] = prev_char;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        row = board.size(), col = board[0].size();
        
        
        for(auto x : words)
            insert_in_trie(x);
        
        for(int i = 0; i < row; i++ )
        {
            for(int j = 0; j < col; j++ )
            {
                dfs(board, i, j, root);
            }
        }
        
        
        return ans;
    }
};