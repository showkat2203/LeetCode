class Solution {
public:
    vector<vector<int>> ans;
    
    void backTrack(vector<int>& nums, vector<int>& temp, int pos, int sz)
    {
        if(pos == sz)
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[pos]);
        backTrack(nums, temp, pos + 1, sz);
        
        temp.pop_back();
        backTrack(nums, temp, pos + 1, sz);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> temp;
        
        backTrack(nums, temp, 0, nums.size());
        
        return ans;
    }
};