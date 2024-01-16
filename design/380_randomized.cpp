class RandomizedSet {
private:
    unordered_set<int> s;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        int n = s.size();
        s.insert(val);
        return n + 1 == s.size();
    }
    
    bool remove(int val) {
        int n = s.size();
        s.erase(val);
        return n - 1 == s.size();
    }
    
    int getRandom() {
        return *next(s.begin(), rand() % s.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */