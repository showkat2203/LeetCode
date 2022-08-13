class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int sz = strs.size();        
        vector<vector<string>> ans;

        int dup = 0;
        map<string, vector<string>> mp;
        
        for( int i = 0; i < sz; i++ )
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(strs[i]);
        }
        
        for(auto it : mp )
        {
            ans.push_back(it.second);
        }
        
        
        return ans;
    }
};