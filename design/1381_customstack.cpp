class CustomStack {
public:
    vector<int> s;
    int n;
    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if (s.size() < n) s.push_back(x);
    }
    
    int pop() {
        if (!s.empty()) {
            int top = s.back();
            s.pop_back();
            return top;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, (int) s.size()); ++i) {
            s[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */