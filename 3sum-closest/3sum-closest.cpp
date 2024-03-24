class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX, sz = nums.size(), ans = 0;
        for(int i = 0; i < sz && diff != 0; i++ ){
            int low = i + 1, high = sz - 1;
            while( low < high ){
                int nearest = nums[i] + nums[low] + nums[high];
                if( abs(target - nearest) <= abs(diff) ){
                    diff = target - nearest;
                    ans = target - diff;
                }
                if( nearest < target ){
                    low++;
                }
                else{
                    high--;
                }
            }
        }

        return ans;
    }
};