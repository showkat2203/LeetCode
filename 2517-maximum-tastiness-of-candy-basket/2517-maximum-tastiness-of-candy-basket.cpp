class Solution {
public:
    bool canPick(vector<int>& price, int k, int mid){
        int last = price[0], cnt = 1;
        
        for(int i = 1; i < price.size(); i++ ){
            if( abs(price[i] - last) >= mid ){
                cnt++;
            }
            else continue;
            if( cnt >= k )  return true;
            last = price[i];
        }
        
        return false;
    }
    
    
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int ans = 0, low = 0, high = price[price.size() - 1];
        
        cout << low << " " << high << endl;
        
        while( low <= high ){
            int mid = low + ( high - low ) / 2;
            
            // cout << low << " " << high << " " << mid << endl;

            if(canPick(price, k, mid)){
                low = mid + 1;
                ans = max(ans, mid);
            }
            else{
                high = mid - 1;
            }
            

        }
        
        return ans;
    }
};