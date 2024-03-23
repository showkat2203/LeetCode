class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banned_set(banned.begin(), banned.end());

        for(auto& ch : paragraph){
            if( isalpha(ch) ){
                ch = tolower(ch);
            }else{
                ch = ' ';
            }
        }
        istringstream iss(paragraph);
        string token, ans = "";
        unordered_map<string, int> mp;
        int maxi = 0;
        while(iss >> token){
            if( banned_set.find(token) == banned_set.end() ){
                mp[token]++;
                if(mp[token] > maxi){
                    maxi = mp[token];
                    ans = token;
                }
            }
        }

        cout << paragraph << endl;

        return ans;
    }
};