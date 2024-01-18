class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        
        int mini = INT_MAX;
        int memo[255] = {0};
        for(auto c : t) memo[c]++;
        int req = t.size();
        int lft = 0, rgt = 0, st = 0;
        
        while( rgt < s.size() ){
            if( memo[s[rgt]] > 0 ) req--;
            memo[s[rgt]]--;
            rgt++;
            
            while( req == 0 ){
                if( rgt - lft < mini ){
                    mini = rgt - lft;
                    st = lft;
                }
                memo[s[lft]]++;
                if(memo[s[lft]] > 0)   req++;
                lft++;
            }
        }
        if(mini == INT_MAX) return "";
        
        string ans = "";
        for(int i = st; i < st + mini; i++ )
            ans += s[i];
        return ans;
    }
};