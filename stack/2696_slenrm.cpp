class Solution {
public:
    int minLength(string s) {
        int len = s.size();
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && ((st.top() == 'A' && c == 'B') || (st.top() == 'C' && c == 'D'))) {
                st.pop();
                len -= 2;
            }
            else st.push(c);
        }
        return len;
    }
};