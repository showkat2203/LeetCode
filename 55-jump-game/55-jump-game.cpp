class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int sz = nums.size() ;
        
        int maxi_pos = 0;
        
        for(int i = 0; i < sz; i++ )
        {
            if( i <= maxi_pos )
            {
                maxi_pos = max(maxi_pos, i + nums[i]);
            }
            else
                break;
        }
        
        if( maxi_pos >= sz - 1)
            return true;
        
        
        return false;
    }
};