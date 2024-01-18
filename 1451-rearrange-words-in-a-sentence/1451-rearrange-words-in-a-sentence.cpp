// #include<bits/stdc++.h> 
// using namespace std;

class Solution {
public:
    string arrangeWords(string s) {
     
        vector<pair<int,pair<int,string>> > v;
        
        stringstream ss(s);
        string word;
        int pos = 0;
        while(ss >> word){
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            v.push_back({word.size(), {pos, word}});
            pos++;
        }
        
        sort(v.begin(), v.end());
        
        int sz = v.size();
        word = "";
        
        for(int i = 0; i < sz; i++ ){
            if( i > 0 )
                word += " ";
            word += v[i].second.second;
        }
        word[0]= toupper(word[0]);
        
        return word;
    }
};