class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int memo[256] = {0};
        int max_len = 0, lft = 0, rgt = 0;
        while( lft <= rgt && rgt < s.size() ){
            memo[s[rgt]]++;
            if( memo[s[rgt]] > 1 ){
                while( lft <= rgt && memo[s[rgt]] > 1 ){
                    memo[s[lft]]--;
                    lft++;
                }
            }
            max_len = max(max_len, rgt - lft + 1);
            rgt++;
        }

        return max_len;
    }
};