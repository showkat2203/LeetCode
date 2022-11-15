class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> words;
        
        int sz = s.size();
        string tmp = "";
        for(int i = 0; i < sz; i++)
        {
            if( s[i] == ' '  )
            {
                if( tmp.size() > 0 )
                {
                    words.push_back(tmp);
                }
                tmp = "";
            }   
            else
            {
                tmp += s[i];
            }
        }
        
        if( tmp.size() > 0 )
        {
            words.push_back(tmp);
        }
        
        tmp = "";
        for(int i = words.size() - 1; i >= 0; i-- )
        {
            tmp += words[i];
            
            if(i != 0)
                tmp += ' ';
        }
        return tmp;
        
    }
};