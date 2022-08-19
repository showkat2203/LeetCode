class Solution {
public:
    int firstUniqChar(string s) {
        
        int sz = s.size();
        int memo[26];
        memset(memo, 0, sizeof(memo));
        
        for(int i = 0; i < sz; i++ )
        {
            int cur = s[i] - 'a';
            memo[cur]++;
        }
        
        for(int i = 0; i < sz; i++ )
        {
            if( memo[s[i] - 'a'] == 1 )
                return i;
        }
        
        return -1;
    }
};