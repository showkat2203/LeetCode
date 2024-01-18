class Solution {
public:
    bool reorderedPowerOf2(int n) {
        map<string, int> mp;
        mp["1"] = 1;
        int res = 1;
        string temp;
        for(int i = 1; i<= 30; i++ ){
            res *= 2;
            temp = to_string(res);
            sort(temp.begin(), temp.end());
            mp[temp] = 1;
        }
        
        temp = to_string(n);
        sort(temp.begin(), temp.end());
        
        if( mp.find(temp) != mp.end()) return true;
        
        return false;
    }
};