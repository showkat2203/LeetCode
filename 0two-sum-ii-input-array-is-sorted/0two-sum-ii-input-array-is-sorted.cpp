class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();
        int lft = 0, rgt = sz - 1;
        vector<int> ans;

        while( lft < rgt ){
            if( nums[lft] + nums[rgt] > target ){
                rgt--;
            }
            else if( nums[lft] + nums[rgt] < target ){
                lft++;
            }
            else{
                return {lft + 1, rgt + 1};
            }
        }

        return ans;
    }
};