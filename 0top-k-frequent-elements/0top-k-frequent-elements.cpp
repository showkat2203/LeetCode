class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        priority_queue< pair<int, int> > pq;

        for(auto x : nums){
            mp[x]++;
        }
        for(auto it : mp){
            pq.push({it.second, it.first});
        }
        int cnt = 0;
        while( !pq.empty() && cnt < k ){
            ans.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        return ans;
    }
};