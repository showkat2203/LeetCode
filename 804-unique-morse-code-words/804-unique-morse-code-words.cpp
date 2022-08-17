class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
     
        char key_val[26][10] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", 
                                "....", "..", ".---", "-.-", ".-..", "--", "-.", 
                                "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", 
                                ".--", "-..-", "-.--", "--.."};
            
            
        // cout << key_val[0] << endl;
            
        map<string, int> mp;
        int sz = words.size();
        
        for(int i = 0; i < sz; i++ )
        {
            string tmp = "";
            for(int j = 0; j < words[i].size(); j++ )
            {
                int pos = words[i][j] - 'a';
                tmp += key_val[pos];
                
            }
            mp[tmp]++;
        }
        
        return mp.size();
        
    }
};