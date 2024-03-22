class Solution {
public:
    string minWindow(string s, string t) {
        int lft = 0, rgt = 0, memo_s[255] = {0}, memo_t[255] = {0};
        for(int i = 0; i < t.size(); i++ ){
            memo_t[t[i]]++;
        }
        string ans = "";
        int matched = 0, st = 0, en = 0, max_len = INT_MAX ;
        while( lft <= rgt && rgt < s.size() ){
            memo_s[s[rgt]]++;
            if(  memo_s[s[rgt]] > 0 && memo_s[s[rgt]] <= memo_t[s[rgt]] ){
                matched++;
            }
            while( lft <= rgt && matched == t.size() ){
                if( rgt - lft + 1 <= max_len ){
                    max_len = rgt - lft + 1 ;
                    st = lft, en = rgt;
                }
                memo_s[s[lft]]--;
                if( memo_s[s[lft]] < memo_t[s[lft]] )
                    matched--;
                lft++;
            }
            rgt++;
        }

        for(int i = st; i <= en; i++ ){
            ans += s[i];
        }
        if( max_len == INT_MAX ) return "";

        return ans;
    }
};