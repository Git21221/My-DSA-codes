class MedianFinder {
public:
    priority_queue<long> large;
    priority_queue<long, vector<long>, greater<long>> small;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        large.push(num);
        small.push(large.top());
        large.pop();
        if(small.size() > large.size()){
            large.push(small.top());
            small.pop();
        }
    }
    
    double findMedian() {
        if(large.size() > small.size()) return large.top();
        return (small.top() + large.top()) / 2.00;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */