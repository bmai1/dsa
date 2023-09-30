class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        string canon = "/";
        stack<string> stk;

        for (int i = 0; i < n; ++i) {
            if (path[i] == '/') continue;
            string s;
            // check curr action
            while (i < n && path[i] != '/') s += path[i++];
            if (s == ".") continue;
            else if (s == "..") {
                // no && else it pushes to stk
                if (!stk.empty()) stk.pop(); 
            }
            else stk.push(s);
        }

        while (!stk.empty()) {
            canon = "/" + stk.top() + canon;
            stk.pop();
        }
        while (canon.size() && canon.back() == '/') canon.pop_back();
        return canon.size() ? canon : "/";
    }
};