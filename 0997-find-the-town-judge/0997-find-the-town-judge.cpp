class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int arr[n + 5], brr[n + 5];
        memset(arr, 0, sizeof arr);
        memset(brr, 0, sizeof brr);
        for(int i = 0; i < trust.size(); i++) {
            brr[trust[i][0]]++;
            arr[trust[i][1]]++;
        }
        int cnt = 0, judge = -1;
        for(int i = 1; i <= n; i++) {
            if(brr[i] == 0) {
                cnt++;
                judge = i;
            }
        }
        if(cnt != 1) {
            return -1;
        }
        if(brr[judge] != 0) {
            return -1;
        }
        if(arr[judge] != n - 1) {
            return -1;
        }
        return judge;
    }
};