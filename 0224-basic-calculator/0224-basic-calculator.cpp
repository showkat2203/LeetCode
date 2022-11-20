class Solution {
public:
    int calculate(string s) {
        
        
        int sz = s.size();
        stack<pair<int, int>> st;
        
        int sum = 0;
        int sign = 1;
        
        for(int i = 0; i < sz; i++ )
        {
            if( isdigit(s[i]) )
            {
                int num = 0;
                while( i < sz && isdigit(s[i]) )
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                sum += ( num * sign);
                sign = 1;
            }
            else if( s[i] == '(')
            {
                st.push(make_pair(sum, sign));
                
                sign = 1;
                sum = 0;
            }
            else if( s[i] == ')')
            {
               sum = st.top().first + (sum * st.top().second);
                st.pop();
            }
            else if( s[i] == '-')
            {
                sign = (-1 * sign);
            }
            
        }
        
        return sum;
    }
};