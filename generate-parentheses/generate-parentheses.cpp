class Solution {
public:
    vector<string> ans;
    void backTrack(int n, int op, int cl, string s ){
        if( s.size() >= n * 2 ){
            // cout << s << endl;
            ans.push_back(s);
            return;
        }
        if( op + 1 <= n)
            backTrack(n, op + 1, cl, s + "(");
        if( cl < op )
            backTrack(n, op, cl + 1, s + ")");
    }

    vector<string> generateParenthesis(int n) {
        backTrack(n, 0, 0, "");
        return ans;
    }
};