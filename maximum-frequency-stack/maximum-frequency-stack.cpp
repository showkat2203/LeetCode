class FreqStack {
public:
    map<int, int> freq;
    map<int, stack<int>> st;
    int maxi = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        maxi = max(maxi, ++freq[val]);
        st[freq[val]].push(val);
    }
    
    int pop() {
        int ret = st[maxi].top();
        st[maxi].pop();
        if( st[maxi].empty() ) maxi--;
        freq[ret]--;
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */