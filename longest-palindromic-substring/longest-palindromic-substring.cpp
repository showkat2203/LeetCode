class Solution {
public:
    pair<int, int> palindromeLength(int low, int high,  string s){
        while(low >= 0 && high < s.size() && s[low] == s[high]){
            low--, high++;
        }
        return {low, high};
    }
    string longestPalindrome(string s) {
        int max_len = 0, st = 0, en = 0;
        for(int i = 0; i < s.size(); i++){
            auto indices = palindromeLength(i, i, s);
            int temp_len = indices.second - indices.first;
            if( temp_len > max_len ){
                max_len = temp_len;
                st = indices.first, en = indices.second;
            }
            
            indices = palindromeLength(i, i + 1, s);
            temp_len = indices.second - indices.first;
            if( temp_len > max_len ){
                max_len = temp_len;
                st = indices.first, en = indices.second;
            }
        }
        cout << st << " " << en << endl;
        string res = "";
        for(int i = st + 1; i < s.size() && i < en; i++) res +=  s[i];
        return res;
    }
};