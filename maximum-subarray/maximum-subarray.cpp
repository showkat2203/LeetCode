class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, max_sum = INT_MIN;
        
        for(auto x : nums){
            sum += x;
            max_sum = max(max_sum, sum);
            if( sum < 0 )
                sum = 0;
        }
        
        return max_sum;
    }
};