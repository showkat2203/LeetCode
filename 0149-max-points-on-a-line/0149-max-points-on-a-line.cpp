// copied
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() < 3) {
            return points.size();
        }
        int maxi = 0;
        for(int i = 0; i < points.size(); i++) {
            for(int j = i + 1; j < points.size(); j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int cnt = 2;
                for(int k = 0; k < points.size(); k++) {
                    if(i == k || j == k) {
                        continue;
                    }
                    int x = points[k][0];
                    int y = points[k][1];
                    int a = x * (y1 - y2) - x1 * (y1 - y2);
                    int b = y * (x1 - x2) - y1 * (x1 - x2);
                    if(a == b) {
                        cnt++;
                    }
                }
                maxi = max(maxi, cnt);
            }
        }
        return maxi;
    }
};