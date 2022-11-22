class Solution {
public:
    
    int dp(int n, vector<int>& memo)
    {
        if( n == 0 )
            return 0;
        
        if( memo[n] != -1 )
            return memo[n];
        
        int min_cnt = 111;
        
        for(int i = 1; i <= sqrt(n); i++ )
        {
            int sq = i * i;
            min_cnt = min(min_cnt, 1 + dp(n - sq, memo));
        }
    
        
        return memo[n] = min_cnt;
    }
    
    int numSquares(int n) {
        vector<int> memo(n + 10, -1);
        
        return dp(n, memo);
    }
};