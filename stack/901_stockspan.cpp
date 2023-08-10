class StockSpanner {
public:
    // stack<int> stk;
    // stack<int> tmp;
    // int next(int price) {
    //     tmp.push(price);
    //     int cnt = 1;
    //     while (!stk.empty() && price >= stk.top()) {
    //         stk.pop();
    //         ++cnt;
    //     }
    //     stk = tmp;
    //     return cnt;
    // }

    stack<pair<int, int>> mstk; // <price, count>
    int next(int price) {
        int cnt = 1;
        while (!mstk.empty() && price >= mstk.top().first) {
            cnt += mstk.top().second; mstk.pop();
        }
        mstk.push({price, cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */