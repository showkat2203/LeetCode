class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if( nums.size() <= 0)
            return 0;
        
        int ans = 0;
        
        set<int> freqs(begin(nums), end(nums));
        
        // set<int> freqs;
        
        // for(int i = 0; i < nums.size(); i++ )
        // {
        //     freqs.insert(nums[i]);
        // }
        
        auto prev = freqs.begin() ;
        cout << *prev << endl;
        int cnt = 1;
        int last = *prev;
        int fl = 0, maxi = 0;
        for(auto it = freqs.begin(); it != freqs.end(); it++ )
        {
            if( fl == 0 )
            {
                fl = 1;
                continue;
            }
            if( *it == last + 1 )
            {
                cnt++;
                maxi = max(maxi, cnt);
            }
            else
            {
                cnt = 1;
            }
            last = *it;
            cout << *it << " ";
        }
        cout << endl;
        
        maxi = max(maxi, cnt);
        
        return maxi;
    }
};