class Solution {
public:
    int firstUniqChar(string s) {
        int memo[26] = {0};
        for(auto ch : s){
            memo[ch - 'a']++;
        }
        for(int i = 0; i < s.size(); i++){
            if( memo[s[i] - 'a']  == 1 ) return i;
        }
        return -1;
    }
};