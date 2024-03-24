class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& words) {
        words.push_back(beginWord);
        unordered_set<string> words_set(words.begin(), words.end());

        int distance = 1;
        
        queue<string> q;
        q.push(beginWord);
        unordered_map<string, int> vis;
        vis[beginWord] = 1;
    
        while( !q.empty() ){
            int sz = q.size();
            for(int i = 0; i < sz; i++ ){
                auto src = q.front(); q.pop();
                if( src == endWord ) return distance;

                words_set.erase(src);
                for(int j = 0; j < src.size(); j++){
                    auto ch = src[j];
                    for(int k = 0; k < 26; k++ ){
                        src[j] = 'a' + k;
                        if( words_set.find(src) != words_set.end() && vis.find(src) == vis.end() ){
                            q.push(src);
                            vis[src] = 1;
                        }
                    }
                    src[j] = ch;
                }
            }
            distance++;
        }
        return 0;
    }
};