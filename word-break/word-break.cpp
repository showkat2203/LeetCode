class Solution {
public:
    unordered_map<string, int> mp;
    unordered_map<int, bool> memo; 

    bool check(int pos, string& s){
        if(pos == s.size()){
            return true;
        }
        if(memo.find(pos) != memo.end()) return memo[pos];

        for(int end = pos + 1; end <= s.size(); end++){
            string currentWord = s.substr(pos, end - pos);
            if(mp.find(currentWord) != mp.end() && check(end, s)){
                return memo[pos] = true;
            }
        }

        return memo[pos] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto& word : wordDict){
            mp[word] = 1;
        }

        return check(0, s);
    }
};
