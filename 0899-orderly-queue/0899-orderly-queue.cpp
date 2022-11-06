class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        
        if( k > 1 )
        {
            sort(s.begin(), s.end());
            return s;
        }
        else
        {
            string ans = s;
            int prev_len = s.size();
            s += s;
            int sz = s.size();
            
            // cout << s << endl;
            for(int i = 0; i < prev_len; i++ )
            {
                ans = min(ans, s.substr(i, prev_len));
                // cout << s.substr(i, prev_len) << endl;
            }
            return ans;
        }
    }
};