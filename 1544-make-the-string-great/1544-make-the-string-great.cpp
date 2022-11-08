class Solution {
public:
    string makeGood(string s) {
        int sz = s.size();
        string ans = "";
        for(int i = 0; i < sz; i++ )
        {
            ans.push_back(s[i]);
            
            while( ans.size() > 0 )
            {
                if( ans[ans.size() - 1] == (s[i + 1] + 32) )
                    ans.pop_back();
                else if( ans[ans.size() - 1] == (s[i + 1] - 32) )
                    ans.pop_back();
                else 
                    break;
                i++;
                
            }
        }
        
        return ans;
    }
};