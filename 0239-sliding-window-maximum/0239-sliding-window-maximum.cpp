// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> ans;
        
//         int lft = 0, rgt = 1;
//         int sz = nums.size();
//         int maxi = nums[lft];
        
//         dequeu<int> dq;
        
//         for(int i = 0; i < k; i++ )
//             maxi = max(maxi, nums[i]), dq.push_back(nums[i]);
        
//         ans.push_back(maxi);
//         rgt = k;
        
//         while( rgt < sz ){
//             if(nums[rgt] > maxi){
//                 maxi = max(max, nums[rgt]);
//                 ans.push_back(maxi);
//                 rgt++;
//                 while(!dq.empty() && dq.front() <= maxi)
//                     dq.pop_front(();
//                 dq.push_back(maxi);
//             }
//             else
//             {
//                 int cur = dq.pop_front();
//                 maxi = max(max, cur);
//                 while(!dq.empty() && dq.front() <= maxi )
//                     dq.pop_front();
            
//                 maxi = max()

//             }
//         }
        
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        // priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < k; i++ )
        {
            pq.push({nums[i], i});
        }

        ans.push_back(pq.top().first);
        cout << pq.top().first << " " << endl;

        int rgt = k, lft = 0;
        while(rgt < nums.size()){

            while( !pq.empty() && pq.top().second <= (rgt - k) )
                pq.pop();
            pq.push({nums[rgt], rgt});
            rgt++;
            ans.push_back(pq.top().first);
            cout << pq.top().first << " " << endl;
        }
        return ans;

    }

};