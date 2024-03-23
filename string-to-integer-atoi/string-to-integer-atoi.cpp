class Solution {
public:
    int myAtoi(string s) {
        double res = 0;

        int pos = 0;
        bool positive = false, negative = false,  digits = false;
        while( pos < s.size() && s[pos] ==' ' ) pos++;
        while( pos < s.size() ){
            if( s[pos] >= '0' && s[pos] <= '9' ){
                res = res * 10 + (s[pos] - '0');
                digits = true;
            }
            else{
                if( digits ) break;
                if( s[pos] == '+' ){
                    if( positive ) return 0;
                    positive = true;
                }
                else if( s[pos] == '-' ){
                    if( negative ) return 0;
                    negative = true;
                }
                else{
                    return 0;
                }
            }
            
            pos++;
        }
        if( negative ) res = -res;
        if( res < INT_MIN ) return INT_MIN;
        if( res > INT_MAX ) return INT_MAX;

        if( positive && negative ) return 0.0;
       
        return res;
    }
};