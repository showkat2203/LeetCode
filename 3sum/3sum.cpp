class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++ ){
            if( i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < nums.size() - 1; j++ ){
                if( j > i + 1 && nums[j] == nums[j - 1]) continue;
                int x = nums[i] + nums[j];
                int y = -x;
                
                auto it = lower_bound(nums.begin() + j + 1, nums.end(), y);
                if( it < nums.end() ){
                    if( y == *it ){
                        ans.push_back({nums[i], nums[j], *it});
                    }
                }
            }
        }

        return ans;
    }
};