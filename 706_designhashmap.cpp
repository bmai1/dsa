class MyHashMap {
public:
    MyHashMap() {}
    vector<pair<int,int>> m;
    void put(int key, int value) {
        for (auto &p : m) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        m.push_back({key, value});
    }
    
    int get(int key) {
        for (auto p : m) {
            if (p.first == key) return p.second;
        }
        return -1;
    }
    
    void remove(int key) {
        for (int i = 0; i < m.size(); ++i) {
            if (m[i].first == key) { 
                m.erase(m.begin() + i);
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */