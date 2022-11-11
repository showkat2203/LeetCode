class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int sz = nums.size() ; 
        
        if(sz <= 0 )
            return 0 ;
        
        int last = nums[0], ele = 1, pos = 1 ;
        
        for(int i = 1; i < sz; )
        {
            if(last == nums[i] )
                i++ ;
            
            else
            {
                nums[pos] = nums[i] ;
                last = nums[pos];
                ele++ ;
                pos++ ;
            }
        }
        
        return ele ;
    }
};