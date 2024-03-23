class Solution {
public:
    double findMedianSortedArrays(vector<int>& x, vector<int>& y) {
        int n = x.size(), m = y.size();
        if( n > m )
            return findMedianSortedArrays(y, x);
        int total = n + m;
        int low = 0, high = n;

        while( low <= high ){
            int mid1 = low + (high - low) / 2;
            int mid2 = (total + 1) / 2 - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if( mid1 < n ) r1 = x[mid1];
            if( mid2 < m ) r2 = y[mid2];
            if( mid1 - 1 >= 0 ) l1 = x[mid1 - 1];
            if( mid2 - 1 >= 0 ) l2 = y[mid2 - 1];

            if( l1 <= r2 && l2 <= r1 ){
                if( total % 2 ) return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if( l1 > r2 ){
                high = mid1 - 1;
            }
            else{
                low = mid1 + 1;
            }
        }
       
        return 0;
    }
};