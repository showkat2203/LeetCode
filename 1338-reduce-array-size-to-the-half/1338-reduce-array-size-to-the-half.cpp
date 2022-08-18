class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int cur_size = 0;
        
        int sz = arr.size();
        map<int, int> occ_mp;
        
        for(int i = 0; i < sz; i++ )
        {
            occ_mp[arr[i]]++;
        }
        
        vector<int> new_vec;
        
        for(auto it : occ_mp)
        {
            new_vec.push_back(it.second);
            cur_size += it.second;
        }
        
        sort(new_vec.rbegin(), new_vec.rend());
        sz = new_vec.size();

    
        int half = cur_size / 2;
        int sum = 0, res = 0;
        for(int i = 0; i < sz; i++ )
        {
            sum += new_vec[i];
            res++;
            if( sum >= half )
                break;
            
        }
        
        return res;
    }
};