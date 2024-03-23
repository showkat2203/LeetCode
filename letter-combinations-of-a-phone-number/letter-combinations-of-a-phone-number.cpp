class Solution {
public:
    
    vector<string> ans;
    unordered_map<int, string> digit_to_char_mp;
    void back(int pos, string temp, string digits){
        if( pos >= digits.size() ){
            if( temp.size() >= 1 ){
                ans.push_back(temp);
            }
            return ;
        }
        int dig = digits[pos] - '0';
        for(int i = 0; i < digit_to_char_mp[dig].size(); i++){
            back(pos + 1, temp + digit_to_char_mp[dig][i], digits);
        }
    }
     Solution(){
        digit_to_char_mp[2] = "abc";
        digit_to_char_mp[3] = "def";
        digit_to_char_mp[4] = "ghi";
        digit_to_char_mp[5] = "jkl";
        digit_to_char_mp[6] = "mno";
        digit_to_char_mp[7] = "pqrs";
        digit_to_char_mp[8] = "tuv";
        digit_to_char_mp[9] = "wxyz";
    }

    vector<string> letterCombinations(string digits) {
        string temp = "";
        back(0, temp, digits );        
        
        return ans;
    }
};