class MyHashMap {
private:
    // Array of linked lists (buckets)
    vector<list<pair<int, int>>> data; 
    static const int capacity = 1009; // prime number for hash distribution
    
    int hash(int key) {
        return key % capacity; 
    }
    
public:
    MyHashMap() {
        data.resize(capacity);
    }
    
    void put(int key, int value) {
        int index = hash(key);
        list<pair<int, int>>& bucket = data[index];

        // update key if exists
        for (auto& p : bucket) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }

        // key doesn't exist, add a new key-value pair
        bucket.push_back({key, value});
    }
    
    int get(int key) {
        int index = hash(key);
        list<pair<int, int>>& bucket = data[index];
        for (auto& p : bucket) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);
        list<pair<int, int>>& bucket = data[index];

        // find key in lists
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
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