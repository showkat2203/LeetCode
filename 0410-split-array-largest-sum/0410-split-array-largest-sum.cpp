class Solution {
public:
    
    int splitReq(vector<int>& nums, int mid){
        int cur = 0, split = 0;
        for(auto x : nums){
            if( cur + x <= mid){
                cur += x;
            }
            else{
                split++;
                cur = x;
            }
        }
        return split + 1;
    }
    
    int splitArray(vector<int>& nums, int k) {
        
        int high = 0, part = 0, low = 0;
        for(int i = 0; i < nums.size(); i++ ){
            high += nums[i];
            low = max(low, nums[i]);
        }
        
        
        int maxi = INT_MIN;
        
        while( low <= high ){
            int mid = low + (high - low) / 2;
            
            if( splitReq(nums, mid) <= k ){
                maxi = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return maxi;
        
    }
};