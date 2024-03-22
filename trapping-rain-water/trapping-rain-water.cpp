class Solution {
public:
    int trap(vector<int>& height) {
        if( height.size() <= 1 ) return 0;

        int sz = height.size(), rgt_maxi = 0;
        vector<int> lft_maxi(sz, 0);
        int ans = 0;
        for(int i = 1; i < sz; i++ ){
            lft_maxi[i] = max(lft_maxi[i - 1], height[i - 1]);
        }

        for(int i = sz - 1; i >= 0; i-- ){
            int save = min(lft_maxi[i], rgt_maxi) - height[i];
            if( save >= 1 )
                ans += save;
            rgt_maxi = max(rgt_maxi, height[i]);
        }

        return ans;
    }
};