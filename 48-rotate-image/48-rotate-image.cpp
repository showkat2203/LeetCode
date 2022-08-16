class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        vector<vector<int>> temp = matrix;
        
        int mrow = matrix.size();
        int mcol = matrix[0].size();
        
        for(int i = 0; i < mrow; i++ )
        {
            for(int j = 0; j < mcol; j++ )
                cout << matrix[i][j] << " ";
            cout << endl;
        }
        
        cout << endl;
        
        for(int i = 0; i < mrow; i++ )
        {
            for(int j = 0; j < mcol; j++ )
                cout << temp[i][j] << " ";
            cout << endl;
        }
        
        int last_col = mcol - 1;
        
        for(int i = 0; i < mrow; i++ )
        {
            int cur_col = 0;
            for(int j = 0; j < mcol; j++ )
            {
                matrix[j][last_col] = temp[i][j];
            }
            last_col--;
        }
        
        cout << endl;
        
        for(int i = 0; i < mrow; i++ )
        {
            for(int j = 0; j < mcol; j++ )
                cout << matrix[i][j] << " ";
            cout << endl;
        }
        
        return;
    }
};