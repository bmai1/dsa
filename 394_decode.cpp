class Solution {
public:
    string decodeString(string s) {
        int num = 0; 
        string ans; 
        stack<string> st;
        stack<int> nums;
        for (char c: s) {
            if (isdigit(c)) {
                num = (num * 10) + c - '0';
            }
            else if (isalpha(c)) {
                ans.push_back(c);
            }
            if (c == '[') {
                st.push(ans);
                nums.push(num);
                ans = "";
                num = 0;
            }
            else if (c == ']') {
                string tmp = ans;
                for (int i = 0; i < nums.top() - 1; ++i) {
                    ans += tmp;
                }
                ans = st.top() + ans;
                st.pop(); nums.pop();
            }
        }
        return ans;
    }
};
