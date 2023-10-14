class Solution {
public:
    int longestValidParentheses(string s) {
        
        // brute force O(n^3)
        for (int i = 0; i < n; ++i) {
            stack<int> stk;
            int j = i;
            for (; j < n; ++j) {
                if (s[j] == '(') stk.push(1);
                else {
                    if (stk.empty()) break;
                    else stk.pop();
                }
            }
            if (stk.empty()) res = max(res, j - i);
        }
        return res;

        // index tracking, O(n)
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') stk.push(i);
            else {
                stk.pop();
                if (stk.empty()) stk.push(i);
                else res = max(res, i - stk.top());
            }
        }
        return res;

        // two-pass iterative
        int n = s.size(), res = 0;
        int o = 0, c = 0;
        for (int i = 0; i < n; ++i) {
            s[i] == '(' ? ++o : ++c;
            if (o == c) res = max(res, o * 2);
            else if (c > o) { o = 0, c = 0; }
        }
        o = 0, c = 0;
        for (int i = n - 1; i >= 0; --i) {
            s[i] == ')' ? ++c : ++o;
            if (c == o) res = max(res, c * 2);
            else if (c < o) { o = 0, c = 0; }
        }
        return res;
    }
};