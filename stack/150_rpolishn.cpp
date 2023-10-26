class Solution {
private:
    bool isOp(string& s) {
        return s == "*" || s == "/" || s == "+" || s == "-";
    }
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0, n1, n2;
        stack<int> stk;
        stk.push(0);
        for (string s : tokens) {
            if (isOp(s)) {
                n1 = stk.top(); stk.pop();
                n2 = stk.top(); stk.pop();
                if (s == "*") stk.push(n2 * n1);
                else if (s == "/") stk.push(n2 / n1);
                else if (s == "+") stk.push(n2 + n1);
                else if (s == "-") stk.push(n2 - n1);
            }
            else stk.push(stoi(s));
        }
        return stk.top();
    }
};