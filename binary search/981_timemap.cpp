class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> m;
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    string get(string key, int timestamp) {
        auto& values = m[key];
        if (values.empty() || values[0].second > timestamp) return "";

        int lo = 0, hi = values.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (values[mid].second == timestamp) return values[mid].first;
            if (values[mid].second < timestamp) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return hi >= 0 ? values[hi].first : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
