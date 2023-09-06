class SmallestInfiniteSet {
public:
    int curr;
    set<int> s;
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1e4; i++) s.insert(i);
    }
    
    int popSmallest() {
        if(!s.empty()) {
            auto topEle = *s.begin();
            s.erase(topEle);
            return topEle;
        }
        return -1;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};