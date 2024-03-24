class Solution {
public:
    int dp[20][200000];
    int solve(int pos, long long sum, vector<int>& coins, long long amount){
        if( sum == amount ){
               return 0;
        }
        if( pos >= coins.size() || sum > amount ){
            return 1e8;
        }
        
        if( dp[pos][sum] != -1 ) return dp[pos][sum];
        int take = 1e8, not_take = 0;
        
        if( coins[pos] + sum <= amount ){
            take = 1 + solve(pos, sum + coins[pos], coins, amount);
        }
        not_take = solve(pos + 1, sum, coins, amount);
        
        return dp[pos][sum] = min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        if( amount <= 0 ) return 0;
        memset(dp, -1, sizeof(dp));
        int res = solve(0, 0, coins, amount);
        if( res == 1e8 ) return -1;
        return res;
    }
};