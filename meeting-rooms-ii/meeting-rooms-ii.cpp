class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 1;
        for(auto x : intervals){
            int st = x[0], en = x[1];
            while( !pq.empty() && pq.top() <= st )
                pq.pop();
            pq.push(en);
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};
