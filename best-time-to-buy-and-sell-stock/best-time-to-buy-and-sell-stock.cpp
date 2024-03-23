class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0, ans = 0;
        for(int i = prices.size() - 1; i >= 0; i-- ){
            ans = max(ans, maxi - prices[i]);
            maxi = max(maxi, prices[i]);
        }

        return ans;
    }
};