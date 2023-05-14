class Solution {
public:
    
    int isBitSet(int& vis, int idx) {
        if( vis & ( 1 << idx) )
            return 1;
        return 0;
    }
    
    void setBit(int &num, int idx){
        num = num | ( 1 << idx );
    }
    
    int solve(vector<int>& nums, map<int, int>& mp, int vis,  int k) {
        
        if( mp.count(vis) ) return mp[vis];
        
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++ ){
            if( isBitSet(vis, i))
                continue;

            for(int j = i + 1; j < nums.size(); j++ ) {
                if( isBitSet(vis, j))
                    continue;
                
                int temp_vis = vis;
                setBit(temp_vis, i);
                setBit(temp_vis, j);
                
                int next_max_score = (k * __gcd(nums[i], nums[j])) + solve(nums, mp, temp_vis, k + 1);
                
                maxi = max(maxi, next_max_score);
            }
        }
        
        return mp[vis] = maxi;
    
    }
    
    int maxScore(vector<int>& nums) {
        
        map<int, int> mp;
        int ans = solve(nums, mp, 0, 1);
        
        
        return ans;
    }
};