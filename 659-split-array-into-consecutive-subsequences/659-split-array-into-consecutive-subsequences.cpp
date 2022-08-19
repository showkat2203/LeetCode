class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        int sz = nums.size();

        map<int, int> exists, could_append;
        
        for(int i = 0; i < sz; i++ )
        {
            exists[nums[i]]++;
        }
        
        for(int i = 0; i < sz; i++ )
        {
            int cur = nums[i];
            if( exists[cur] == 0 )
                continue;
            
            if( could_append[cur] > 0 && exists[cur] > 0)
            {
                exists[cur]--;
                could_append[cur]--;
                
                could_append[cur + 1]++;
            }
            else if(exists[cur + 1] > 0 &&  exists[cur + 2] > 0 )
            {
                exists[cur]--;
                exists[cur + 1]--;
                exists[cur + 2]--;
                
                could_append[cur + 3]++;
            }
            else
                return false;
        }
        
        
        return true;
        
    }
};