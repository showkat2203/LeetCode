/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        unsigned int ans = 1;
        unsigned int low = 1, high = INT_MAX;
        
        while( low <= ( (high + low) / 2) )
        {
            ans = (high + low) / 2;
            int gue = guess(ans);
            if( gue == 0 )
                return ans;
            if( gue < 0 )
                high = ans - 1;
            else
                low = ans + 1;
            // cout << "yes " << ans << endl;
            
        }
        

        
        return ans;
    }
};