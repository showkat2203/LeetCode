class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        int erase_req = 0;
        int en = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++ )
        {
            if( intervals[i][0] < en )
            {
                en = min(en, intervals[i][1]);
                erase_req++;
            }
            else
                en = intervals[i][1];
        }

        return erase_req;
    }
};