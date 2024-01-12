class Solution {
public:
    
    int canCarry(vector<int>& weights, int sz){
        
        int cur = 0, day = 0;
        
        for(auto x : weights){
            if( cur + x <= sz){
                cur += x;
            }
            else{
                cur = x;
                day++;
            }
        }
        return day + 1;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = INT_MAX, high = 0, maxi = 0;
        for(auto x : weights){
            low = min(low, x);
            maxi = max(maxi, x);
            high += x;
        }
        int ship_size = INT_MAX;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if( canCarry(weights, mid) <= days && mid >= maxi){
                high = mid - 1;
                ship_size = min(mid, ship_size) ;
            }
            else{
                low = mid + 1;
            }
        }
        
        return ship_size;
        
    }
};