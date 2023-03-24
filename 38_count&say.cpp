class Solution {
private:
    string helper(string s, int n) {
        string res;
        unordered_map<char, int> m;
        int l = s.length(), index = 0;
        while (l > 0) {
            char curr = s[index];
            int i = index;
            while (s[i] == curr) { m[s[i++]]++, l--; }
            // for (int i = index; i < s.length(); ++i) {
            //     if (s[i] == target) {
            //         m[s[i]]++, l--;
            //     }
            //     else break;
            // }
            res += to_string(m[s[index]]); 
            res += s[index]; 
            index += m[s[index]];
            // cout << "TEST    " << res << endl; 
            m.clear();
        }
        return n > 2 ? helper(res, n - 1) : res;
    }
public:
    string countAndSay(int n) {
        return n == 1 ? "1" : helper("1", n);
    }
};
