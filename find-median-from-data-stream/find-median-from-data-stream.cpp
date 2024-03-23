class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int items;
    MedianFinder() {
        items = 0;
    }
    
    void addNum(int num) {
        if( items % 2 == 0 ){
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else{
            min_heap.push(num);
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        items++;
    }
    
    double findMedian() {
        if( max_heap.size() == 0 && min_heap.size() == 0 )
            return 0.0;
        
        if( items % 2 ){
            return min_heap.top();
        }

        return (max_heap.top() + min_heap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */