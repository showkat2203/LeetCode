class Solution {
public:
    string removeDuplicates(string s) {
        
        int memo[26];
        string ans = "";
       
        for(int i = 0; i < s.size(); i++ )
        {
            ans += s[i];
            while( ans.size() > 0 && ans[ans.size() - 1] == s[i + 1])
            {
                ans.pop_back();
                i++;
            }
        }
        
        return ans;
    }
};