class Solution {
public:
    int maxArea(vector<int>& height) {
        int lft = 0, rgt = height.size() - 1 ;
        int ans = 0;

        while( lft <= rgt ){
            ans = max(ans, min( height[lft], height[rgt] ) * ( rgt - lft) );
            if( height[lft] <= height[rgt] ){
                lft++;
            }
            else{
                rgt--;
            }
        }

        return ans;
    }
};