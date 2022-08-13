class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int up = 0, down = row - 1;
        int lft = 0, rgt = col - 1;
        
        
        while(up <= down && lft <= rgt )
        {
            
             // cout << " Start " << up << " " << down << " " << lft << " " << rgt << endl;
            
//             Go right
            int cur_row = up;
            for(int i = lft; i <= rgt; i++ )
            {
                ans.push_back(matrix[cur_row][i]);
                // cout << "added 1 " << endl; 
                
            }
            up++;
            
            // go down
            int cur_col = rgt;
            for(int i = up; i <= down; i++ )
            {
                ans.push_back(matrix[i][cur_col]);
                // cout << "added 2 " << endl; 
            }
            rgt--;
            
            // go left
            cur_row = down;
            for(int i = rgt; up <= down && i >= lft; i-- )
            {
                ans.push_back(matrix[cur_row][i]);
                // cout << "added 3 " << endl; 
                
            }
            down--;
            
            // go up
            cur_col = lft;
            for(int i = down; lft <= rgt && i >= up; i-- )
            {
                ans.push_back(matrix[i][cur_col]);
                // cout << "added 4 " << endl; 

            }
            
            lft++;
            // cout << "END ------------- " << up << " " << down << " " << lft << " " << rgt << endl;
        }
        
        if( ans.size() > (row*col))
            ans.pop_back();
        
        
        return ans;
    }
};