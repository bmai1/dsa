class Solution {
public:
    string removeStars(string s) {
        string ans;
        // stack<char> stk;
        // for (char c : s) {
        //     if (c == '*') { stk.pop(); }
        //     else stk.push(c);
        // }
        // while (!stk.empty()) {
        //     ans += stk.top();
        //     stk.pop();
        // }
        // reverse(ans.begin(), ans.end());
        // return ans;
        for (char c : s) {
            if (c == '*') { ans.pop_back(); }
            else ans += c;
        }
        return ans;
    }
};
