class Solution {
public:
    static bool cmp(const string &x, const string &y){
        string xx = x.substr(x.find(' '));
        string yy = y.substr(y.find(' '));

        if( xx == yy ) return x < y;
        return xx <= yy;
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> result, digit_log;
        int count = 0;
        for(auto log : logs){
            if( log.back() >= 'a' && log.back() <= 'z' )
                result.push_back(log);
            else
                digit_log.push_back(log);
        }
        sort(result.begin(), result.end(), cmp);
        for(auto dig : digit_log)
            result.push_back(dig);

        return result;
    }
};