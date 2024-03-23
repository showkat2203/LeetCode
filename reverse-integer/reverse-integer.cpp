class Solution {
public:
    int reverse(int x) {
        int flag = 1, num = 0;
        if( x < 0 ){
            flag = -1;
            x = abs(x);
        }

        while( x ){
            if( num * flag > INT_MAX / 10 || num * flag < INT_MIN / 10) return 0;
            num = num * 10 + ( x % 10);
            x /= 10;
        }
        return num * flag;
    }
};