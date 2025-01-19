class Solution {
public:
    bool isBalanced(string num) {
        int e = 0, o = 0, i = 0;
        while (!num.empty()) {
            int n = num.back() - '0';
            if (i++ % 2 == 0) e += n;
            else o += n;
            num.pop_back();
        }
        return e == o;
    }
};
