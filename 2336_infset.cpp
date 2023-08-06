class SmallestInfiniteSet {
public:
    int curMin = 1;
    set<int> s;
    int popSmallest() {
        if (!s.empty()) {
            int n = *s.begin(); s.erase(s.begin());
            return n;
        }
        return curMin++; 
    }
    void addBack(int num) {
        if (num < curMin)
            s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */