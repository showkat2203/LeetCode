#define p pair<int, pair<int, int>>
class Solution {
public:
    int m, n;
    int bfs(int i, int j, int u, int v, vector<vector<int>>& nums) {
        vector<vector<bool>> explored(m, vector<bool>(n));
        queue<pair<int, int>> q;
        q.push({i, j});
        explored[i][j] = true;
        int cnt = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front(); q.pop();
                if (x == u && y == v) return cnt;
                for (auto [dx, dy] : vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && nums[nx][ny] && !explored[nx][ny]) {
                        q.push({nx, ny});
                        explored[nx][ny] = true;
                    }
                }
            }
            ++cnt;
        }
        return -1;
    }
    
    int cutOffTree(vector<vector<int>>& nums) {
        m = nums.size(), n = nums[0].size();
        priority_queue<p, vector<p>, greater<>> trees;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (nums[i][j] > 1) trees.push({nums[i][j], {i, j}});
                
        int x = 0, y = 0, ans = 0;
        while (!trees.empty()) {
            auto [h, pos] = trees.top(); trees.pop();
            int steps = bfs(x, y, pos.first, pos.second, nums);
            if (steps == -1) return -1;
            ans += steps, x = pos.first, y = pos.second;
        }
        return ans;
    }
};
