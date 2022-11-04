class Solution {
public:
    
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' )
            return true;
    
        if( c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
    
    string reverseVowels(string s) {
        
        int sz = s.size() - 1;
        int fst = 0, scnd = s.size() - 1;
        for(fst = 0; fst < scnd; fst++ )
        {
            if( isVowel(s[fst]) )
            {
                while( !isVowel(s[scnd]) && scnd > fst)
                {
                    scnd--;
                }
                if( scnd > fst ) 
                {
                    swap(s[fst], s[scnd]);
                    scnd--;
                }
            }
            cout << s[fst] << " " << s[scnd] << endl;
        }
        return s;
    }
};