class Solution {
public:
    int distance(vector<int> v){
        return v[0] * v[0] + v[1] * v[1];
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for(auto x : points){
            pq.push({distance(x), x});
            if( pq.size() > k ) pq.pop();
        }
        vector<vector<int>> ans;
        while( !pq.empty() ){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};