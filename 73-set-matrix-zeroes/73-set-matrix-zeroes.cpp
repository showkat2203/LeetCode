class Solution {
public:
    void visit_by_columns(vector<vector<int>>& matrix, int cur_col, int mrow)
    {
        for(int i = 0; i < mrow; i++ )
            matrix[i][cur_col] = 0;
    }
    
    void visit_by_rows(vector<vector<int>>& matrix, int cur_row, int mcol)
    {
        for(int i = 0; i < mcol; i++ )
            matrix[cur_row][i] = 0;
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        int mrow = matrix.size();
        int mcol = matrix[0].size();
        
        int first_row = 1;
        int first_col = 1;
        
        for(int i = 0; i < mcol; i++)
        {
            if( matrix[0][i] == 0)
            {
                first_row = 0;
                break;
            }
        }
        
        for(int i = 0; i < mrow; i++)
        {
            if( matrix[i][0] == 0)
            {
                first_col = 0;
                break;
            }
        }
        
        for(int i = 1; i < mrow; i++ )
        {
            int cur_col = 1;   
            while( cur_col < mcol )
            {
                
                if( matrix[i][cur_col] == 0 )
                {
                    matrix[i][0] = 0;
                    break;
                }
                cur_col++;    
            }
        }
        
        for(int i = 1; i < mcol; i++ )
        {
            int cur_row = 1;   
            
            while( cur_row < mrow )
            {
                if( matrix[cur_row][i] == 0 )
                {
                    matrix[0][i] = 0;
                    break;
                }
                cur_row++;
            }
        }

        for(int i = 1; i < mrow; i++ )
        {
            if( matrix[i][0] == 0 )
            for(int j = 0; j < mcol; j++ )
            {
                matrix[i][j] = 0;
            }
        }
        
        for(int i = 1; i < mcol; i++ )
        {
            if( matrix[0][i] == 0 )
            for(int j = 0; j < mrow; j++ )
            {
                matrix[j][i] = 0;
            }
        }
        
        
        
        if( first_row == 0 )
        {
            for(int i = 0; i < mcol; i++)
            {
                matrix[0][i] = 0;
            }
        }
        
        if(first_col == 0 )
        {
            for(int i = 0; i < mrow; i++)
            {
                matrix[i][0] = 0;
            }
        }
        
        return;
    }
};