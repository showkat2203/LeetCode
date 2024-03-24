class LRUCache {
public:
    list<int> l;
    map<int, pair<int, list<int> :: iterator>> mp;
    int cap;
    LRUCache(int _cap) {
        cap = _cap;
    }
    
    int get(int key) {
        if( mp.find(key) != mp.end() ){
            int value = mp[key].first;
            auto x = mp[key].second;
            l.erase(x);
            l.push_front(key);
            mp[key] = {value, l.begin()};

            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if( mp.find(key) == mp.end() ){
            if( l.size() >= cap ){
                int rmv = l.back();
                mp.erase(rmv);
                l.pop_back();
            }
            l.push_front(key);
            mp[key] = {value, l.begin()};
        }
        else{
            auto x = mp[key].second;
            l.erase(x);
            l.push_front(key);
            mp[key] = {value, l.begin()};

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */